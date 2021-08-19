DELETE FROM `quest_request_items` WHERE `ID` IN (26797 /*A Daughter's Love*/, 26795 /*Mor'Ladim*/, 26693 /*The Dark Tower*/, 26640 /*Unspeakable Atrocities*/, 26636 /*Bravo Company Field Kit: Camouflage*/, 26637 /*Bravo Company Field Kit: Chloroform*/, 26607 /*They Drew First Blood*/, 26573 /*His Heart Must Be In It*/, 26569 /*Surveying Equipment*/, 26562 /*And Last But Not Least... Danforth*/, 26560 /*Jorgensen*/, 26587 /*Breaking Out is Hard to Do*/, 26571 /*Weapons of War*/, 26545 /*Yowler Must Die!*/, 26513 /*Like a Fart in the Wind*/, 26544 /*They've Wised Up...*/, 26514 /*Canyon Romp*/, 26510 /*We Must Prepare!*/, 26508 /*Nida's Necklace*/, 26509 /*An Unwelcome Guest*/, 26505 /*Parker's Report*/, 26503 /*Still Assessing the Threat*/, 26506 /*Franks and Beans*/, 26230 /*Feast or Famine*/, 26152 /*Wanted: James Clark*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(26797, 0, 0, 0, 0, 'Leave me be...', 0), -- A Daughter's Love
(26795, 0, 0, 0, 0, 'I don\'t blame you if you\'re having trouble with him, $n. Some of our strongest Watchers have been lost to Mor\'Ladim.', 0), -- Mor'Ladim
(26693, 0, 0, 0, 0, 'I hear you loud and clear, $n.', 0), -- The Dark Tower
(26640, 6, 0, 0, 0, 'They got Brubaker?', 0), -- Unspeakable Atrocities
(26636, 1, 0, 0, 0, 'Leaves and poop - that\'s what I need.', 0), -- Bravo Company Field Kit: Camouflage
(26637, 6, 0, 0, 0, 'Did you recover the glands?', 0), -- Bravo Company Field Kit: Chloroform
(26607, 6, 0, 0, 0, 'You again?', 0), -- They Drew First Blood
(26573, 0, 0, 0, 0, 'Did you locate the headband and amulet?', 0), -- His Heart Must Be In It
(26569, 6, 0, 0, 0, 'Did you recover the spyglasses?', 0), -- Surveying Equipment
(26562, 5, 0, 0, 0, 'Well look at that! The team\'s all here... everyone but Keeshan.', 0), -- And Last But Not Least... Danforth
(26560, 0, 0, 0, 0, 'Messner! Damn, it\'s good to see a friendly face. Get me out of here!', 0), -- Jorgensen
(26587, 6, 0, 0, 0, 'Did you get the cage key?', 0), -- Breaking Out is Hard to Do
(26571, 0, 0, 0, 0, 'Did you terminate Murdunk and Homurk?', 0), -- Weapons of War
(26545, 6, 0, 0, 0, 'Do you have the Blackrock invasion plans?', 0), -- Yowler Must Die!
(26513, 6, 0, 0, 0, 'Did you recover the supplies?\n', 0), -- Like a Fart in the Wind
(26544, 6, 0, 0, 0, 'What have you found out?', 0), -- They've Wised Up...
(26514, 6, 0, 0, 0, 'Did you recover those collars?', 0), -- Canyon Romp
(26510, 6, 0, 0, 0, 'Have you recovered the gnomecorder?', 0), -- We Must Prepare!
(26508, 24, 0, 0, 0, 'Hi.  I miss my necklace.  My daddy got it for me.  Daddy says that there are monsters in the lake.  Did you beat up any monsters?', 0), -- Nida's Necklace
(26509, 6, 0, 0, 0, 'Is Bellygrub still at it or were you able to rid Lakeshire of the pest once and for all?', 0), -- An Unwelcome Guest
(26505, 6, 0, 0, 0, 'Where did I put my monocle?! Conacher is that you?', 0), -- Parker's Report
(26503, 0, 0, 0, 0, 'Did you find the gnoll plans?', 0), -- Still Assessing the Threat
(26506, 6, 0, 0, 0, 'Have you gotten my ingredients?', 0), -- Franks and Beans
(26230, 396, 0, 0, 0, 'Dirt pies don\'t make themselves - usually.', 0), -- Feast or Famine
(26152, 6, 0, 0, 0, 'Turning in a bounty?', 0); -- Wanted: James Clark

UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=25881 WHERE `ID`=26782; -- The Mosh'Ogg Bounty
UPDATE `quest_request_items` SET `CompletionText`='Hello, $n.  Did the goblin Krazek fix my pot??' WHERE `ID`=26765; -- Return to Corporal Kaleb
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26742; -- Bloodscalp Insight
UPDATE `quest_request_items` SET `CompletionText`='Make sure you handle that stuff carefully, $n.  We don\'t know what it is.' WHERE `ID`=26734; -- The Source of the Madness
UPDATE `quest_request_items` SET `CompletionText`='There\'s something not quite healthy about this elixir, $n.  Even though I haven\'t completed my analysis, I can sense it.' WHERE `ID`=26733; -- Control Sample
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26721; -- The Jitters-Bugs
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26685; -- Classy Glass
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Hi, $n.  Do you have those rot blossoms for me yet?' WHERE `ID`=26661; -- Gather Rot Blossoms
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26655; -- Deliver the Thread
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26684; -- The Insane Ghoul
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26654; -- Return the Comb
UPDATE `quest_request_items` SET `CompletionText`='Hail, $n.  Did you get that lump meat for me?' WHERE `ID`=26623; -- Dusky Crab Cakes
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26620; -- Seasoned Wolf Kabobs
UPDATE `quest_request_items` SET `CompletionText`='The flame will not burn for long without ooze, $n. We used to use oil back in the day, but it was hard to come by!' WHERE `ID`=26347; -- Keeper of the Flame
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=26296; -- Evidence Collection
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=25881 WHERE `ID`=26295; -- Propaganda
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=26266; -- Hope for the People
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='What have you got there, $n?' WHERE `ID`=26252; -- Heart of the Watcher
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=25881 WHERE `ID`=26241; -- Westfall Stew
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26214; -- Hot On the Trail: Murlocs
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26213; -- Hot On the Trail: The Riverpaw Clan
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='We don\'t need any civilian vigilante types getting involved, kid. Leave this one to the professionals.' WHERE `ID`=184; -- Furlbrow's Deed
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Hail, $n.  Have you been killing Gnolls...?' WHERE `ID`=11; -- Riverpaw Gnoll Bounty
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Did you find the Collector?  Did you discover whom he\'s working for?' WHERE `ID`=147; -- Manhunt
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='I have been commissioned by the Stormwind Army to supply their people with cloth and leather armor.$B$BIf you have a marker for me, then I\'d be happy to make you something.' WHERE `ID`=59; -- Cloth and Leather Armor
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='How goes the hunting, $n?' WHERE `ID`=46; -- Bounty on Murlocs
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Hello, $n.  Have you discovered the fates of Rolf and Malakai?' WHERE `ID`=71; -- Report to Thomas
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='I\'m running low on linen, $n.  Do you have any for me?' WHERE `ID`=83; -- Fine Linen Goods
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='That deadline isn\'t getting any further away, $c. Please hurry and collect those bundles of wood.' WHERE `ID`=5545; -- A Bundle of Trouble
UPDATE `quest_request_items` SET `CompletionText`='What?!?  We haven\'t had our people working the Elwynn mines for months!$B$BLet me see that note you have...' WHERE `ID`=123; -- The Collector
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Did you deliver my letter to Tommy Joe?  What did he say??' WHERE `ID`=114; -- The Escape
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Do you have that crystal kelp?  I\'m sure Maybell is anxious to see her beau...' WHERE `ID`=112; -- Collecting Kelp
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=60; -- Kobold Candles
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='You have a note from \"Gramma\" Stonefield, eh?  I haven\'t seen Mildred in years!  I wonder what she has to say...' WHERE `ID`=107; -- Note to William
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Psst!  You have that Gold Dust for me...for me?' WHERE `ID`=47; -- Gold Dust Exchange
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Hello, $n.  Have you found my necklace?' WHERE `ID`=87; -- Goldtooth
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Ugh... I\'m starving!  Do you have that pie for me, $n?' WHERE `ID`=84; -- Back to Billy
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='You have what??  Maybell is the light of my dull life.  Hurry, let me see her letter!' WHERE `ID`=106; -- Young Lovers
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='I don\'t think it\'s right feeding the boy who stole my necklace in the first place, but if that\'s what it takes to get back what\'s mine, then so be it!$B$BDo you have that boar meat?' WHERE `ID`=86; -- Pie for Billy
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=16; -- Give Gerard a Drink
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Did you see her yet?  Did you get her?' WHERE `ID`=88; -- Princess Must Die!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26396; -- Return to Argus
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26395; -- Dungar Longdrink
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26394; -- Continue to Stormwind
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=334; -- Package for Thurman
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=332; -- Wine Shop Advert
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=333; -- Harlan Needs a Resupply
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26393; -- A Swift Message
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26389; -- Blackrock Invasion
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=5, `CompletionText`='Rescue our soldiers!', `VerifiedBuild`=25881 WHERE `ID`=28808; -- Fear No Evil

UPDATE `quest_request_items` SET `VerifiedBuild`=25881 WHERE `ID` IN (26774, 26772, 26729);

DELETE FROM `quest_request_items` WHERE `ID` IN (27199 /*Ashes to Ashes*/, 27172 /*The Writhing Haunt*/, 27171 /*Ambushed!*/, 27167 /*A Mighty Hunger*/, 27166 /*Go Fletch!*/, 27164 /*Araj the Summoner*/, 26809 /*Backdoor Dealings*/, 26825 /*Dask "The Flask" Gobfizzle*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(27199, 0, 0, 0, 0, 'You will find them to the east, $n.  Do not fail me.', 25928), -- Ashes to Ashes
(27172, 0, 0, 0, 0, 'Did Valorfist send you?  He doesn\'t know when to let up, does he?', 0), -- The Writhing Haunt
(27171, 0, 0, 0, 0, 'What happened at Uther\'s Tomb, $n?', 0), -- Ambushed!
(27167, 0, 0, 0, 0, 'We\'ve traveled a long way.  Anything you can spare would be appreciated.', 0), -- A Mighty Hunger
(27166, 0, 0, 0, 0, 'It\'s good to see you back, $n.', 0), -- Go Fletch!
(27164, 0, 0, 0, 0, 'Araj is a formidable opponent.  Be prepared.', 0), -- Araj the Summoner
(26809, 0, 0, 0, 0, 'You have not done as I asked, $r.  Perhaps I was wrong to have selected you for this task...', 25928), -- Backdoor Dealings
(26825, 0, 0, 0, 0, 'You got something that needs mixing?', 0); -- Dask "The Flask" Gobfizzle

UPDATE `quest_request_items` SET `VerifiedBuild`=25928 WHERE `ID`=26823; -- Too Big For His Britches

UPDATE `quest_request_items` SET `CompletionText`='That\'s some precious cargo you carry there, $n.' WHERE `ID`=27826; -- Into the Dragon's Mouth

DELETE FROM `quest_request_items` WHERE `ID` IN (26192 /*Orphans Like Cookies Too!*/, 28416 /*Burning Vengeance*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(26192, 6, 0, 0, 0, 'Were you able to find the confectioners\' sugar?', 0), -- Orphans Like Cookies Too!
(28416, 0, 0, 0, 0, 'You have trouble finding them?  They\'re to the south, $n.', 25950); -- Burning Vengeance

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=27354; -- Mastering the Arcane
UPDATE `quest_request_items` SET `CompletionText`='You\'ve arrived, $n.' WHERE `ID`=28316; -- A Deal With a Dragon
UPDATE `quest_request_items` SET `EmoteOnComplete`=35 WHERE `ID`=28415; -- SEVEN! YUP!

UPDATE `quest_request_items` SET `VerifiedBuild`=25950 WHERE `ID`=28172; -- Done Nothing Wrong

DELETE FROM `quest_request_items` WHERE `ID` IN (44558 /*Crushing the Crown*/, 27354 /*Mastering the Arcane*/, 24611 /*A Gift for the Prophet*/, 24610 /*A Gift for the High Priestess of Elune*/, 33514 /*The Ritual*/, 30998 /*A New Enemy*/, 31493 /*Just for Safekeeping, Of Course*/, 25770 /*Keg Run*/, 25395 /*The Stolen Keg*/, 27016 /*The Joy of Boar Hunting*/, 26176 /*Onward to Thelsamar*/, 26145 /*The Trogg Threat*/, 26112 /*Demanding Answers*/, 24609 /*A Gift for a Lord of Ironforge*/, 29352 /*A Fowl Shortage*/, 25840 /*Eliminate the Resistance*/, 26170 /*The Final Ritual*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(44558, 0, 0, 0, 0, 'Did you teach \'em a lesson?', 25961), -- Crushing the Crown
(27354, 1, 0, 0, 0, 'Did you bring the materials I\'ll need for your weapon?', 0), -- Mastering the Arcane
(24611, 0, 0, 0, 0, 'Well met, $c. Did you have something for me?', 0), -- A Gift for the Prophet
(24610, 0, 0, 0, 0, 'Well met, $c. Did you have something for me?', 0), -- A Gift for the High Priestess of Elune
(33514, 0, 0, 0, 0, 'Quickly $n, you must stop the ritual!  Amnennar cannot be allowed to return.', 25961), -- The Ritual
(30998, 0, 0, 0, 0, 'Have you collected the insignia?', 0), -- A New Enemy
(31493, 1, 0, 0, 0, 'It\'s imperative that I get my hands on the codex.', 0), -- Just for Safekeeping, Of Course
(25770, 0, 0, 0, 0, 'Aye? What\'ve you got for me there?', 0), -- Keg Run
(25395, 6, 0, 0, 0, 'Do you have it? Is the poor thing intact?', 0), -- The Stolen Keg
(27016, 0, 1, 0, 0, 'It\'s okay, $n. It happens to a lot of $cs. Being unable to live up to my greatness is nothing to be ashamed of.', 25961), -- The Joy of Boar Hunting
(26176, 0, 0, 0, 0, 'What can I do for you?', 0), -- Onward to Thelsamar
(26145, 6, 0, 0, 0, 'Do you have eight trogg stone teeth to show me?  If not, there is still work to be done, $n.', 0), -- The Trogg Threat
(26112, 1, 0, 0, 0, 'What is the meaning of this intrusion?', 0), -- Demanding Answers
(24609, 0, 0, 0, 0, 'Well met, $c. Did you have something for me?', 0), -- A Gift for a Lord of Ironforge
(29352, 6, 0, 0, 0, 'The chickens, $n, do ye have them or not?', 0), -- A Fowl Shortage
(25840, 0, 1, 0, 0, 'Did you find and kill Battok the Berserker?', 25961), -- Eliminate the Resistance
(26170, 0, 0, 0, 0, 'Quickly, friend.  This is but the calm before the storm.', 25961); -- The Final Ritual

UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26038; -- Attack on the Tower
UPDATE `quest_request_items` SET `CompletionText`='Have you retrieved any Stromgarde Badges, $n?  The Syndicate must learn they cannot profit from our dead.' WHERE `ID`=26095; -- Stromgarde Badges
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='$n, hello again. Have you found an azure agate yet?' WHERE `ID`=26037; -- Trelane's Defenses
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4604; -- More Sparklematic Action
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='It would seem that the device needs some sort of grime-encrusted object to clean and three silver coins to get the contraption working.  So long as both are present, the Sparklematic 5200 should work...' WHERE `ID`=4602; -- The Sparklematic 5200!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='Our goal is the wand, $n. Focus on that for now.' WHERE `ID`=26036; -- Wand over Fist
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26035; -- Worth Its Weight in Gold
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='We appreciate your help in looking for that courier, $n.$B$BWhile you were gone, Kin saw an apothecary come out of that same house to the south of here. I\'m confident that they\'re up to no good--I just need proof of it before we go off and do something rash.$B$BHave you had any luck yet?' WHERE `ID`=26110; -- Just Like Old Times
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=25854; -- I'll Call Him Bitey
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=25815; -- The Third Fleet
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=25734; -- Down In Thelgen Rock
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25736; -- The Floodsurge Core
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=27077; -- Clutching at Chaos
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=27031; -- Wing Nut
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID`=27030; -- Foxtails By The Handful
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=27025; -- Thistle While You Work
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26864; -- The Bearer of Gnoll-edge
UPDATE `quest_request_items` SET `CompletionText`='Do you have that Miners\' Gear, $n?' WHERE `ID`=26863; -- Filthy Paws
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26845; -- Who's In Charge Here?
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26842; -- Out of Gnoll-where
UPDATE `quest_request_items` SET `CompletionText`='Hello, $n.  Do you have word of my friend Hildelve?' WHERE `ID`=26855; -- A Pilot's Revenge
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=25997; -- Dark Iron Scheming
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=25937; -- Priceless Treasures
UPDATE `quest_request_items` SET `EmoteOnComplete`=20 WHERE `ID`=314; -- Protecting the Herd
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=412; -- Operation Recombobulation
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=25668; -- Pilfered Supplies
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26380; -- Bound for Kharanos
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=315; -- The Perfect Stout
UPDATE `quest_request_items` SET `CompletionText`='I\'m going to need those crag boar ribs and a mug of Rhapsody Malt, $n.' WHERE `ID`=384; -- Beer Basted Boar Ribs
UPDATE `quest_request_items` SET `CompletionText`='Shayana\'s plan is a good one.  Do you have the vessel, $n?' WHERE `ID`=26186; -- Demoniac Vessel
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=27904; -- Breath of Mist
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID`=27851; -- Cutting Supply

DELETE FROM `quest_request_items` WHERE `ID` IN (27325 /*The Drums of War*/, 27320 /*The Writ of History*/, 27316 /*The Rattle of Bones*/, 25873 /*Horn of the Traitor*/, 25825 /*Deliver the Goods*/, 28031 /*Special Delivery for Brivelthwerp*/, 25627 /*Two-Tusk Takedown*/, 25609 /*Sunken Treasure*/, 25778 /*Fake Gold for Black Gold*/, 25774 /*Fool's Gold*/, 25756 /*Get Zherin!*/, 25515 /*Down in the Deeps*/, 25524 /*In the Outhouse*/, 25504 /*Do Me a Favor?*/, 29032 /*Get Them While They're Young*/, 28523 /*More Beads for Salfa*/, 13644 /*That Which Has Risen*/, 13506 /*Reason to Worry*/, 13596 /*Twilight Plans*/, 13591 /*Disturbing Connections*/, 13569 /*The Ritual Bond*/, 28529 /*Writings of the Void*/, 25451 /*Pristine Yeti Hide*/, 26401 /*Return to Vestia*/, 25394 /*More Than Illness*/, 27429 /*Raze Direhorn Post!*/, 27242 /*Raptor Captor*/, 27427 /*Arms of the Grimtotems*/, 27426 /*Confirming the Suspicion*/, 27284 /*The Black Shield*/, 27263 /*Lieutenant Paval Reethe*/, 27252 /*The Black Shield*/, 27247 /*Captain Vimes*/, 27246 /*The Orc Report*/, 27237 /*Recover the Cargo!*/, 27236 /*Secondhand Diving Gear*/, 27235 /*Renn McGill*/, 27234 /*Defias in Dustwallow?*/, 27212 /*Discrediting the Deserters*/, 27220 /*Nat's Bargain*/, 27211 /*Propaganda War*/, 27218 /*Dastardly Denizens of the Deep*/, 27217 /*Thresher Oil*/, 27210 /*Traitors Among Us*/, 28398 /*The Pyromancer's Grimoire*/, 24597 /*A Gift for the King of Stormwind*/, 27103 /*Shards of the Felvine*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(27325, 1, 0, 0, 0, 'The tauren love their drums. I can only imagine the Drums of War will be somehow different from the others.', 0), -- The Drums of War
(27320, 1, 0, 0, 0, 'We\'ll need the actual writ, not just any tauren scroll hanging.', 0), -- The Writ of History
(27316, 1, 0, 0, 0, 'That\'s the fabled Rattle of Bones, $n!', 0), -- The Rattle of Bones
(25873, 6, 0, 0, 0, 'What\'s this, $c?', 0), -- Horn of the Traitor
(25825, 6, 0, 0, 0, 'What\'s this? Is that oil?!', 0), -- Deliver the Goods
(28031, 6, 0, 0, 0, 'That\'s not what I think it is? Is it?!', 0), -- Special Delivery for Brivelthwerp
(25627, 6, 0, 0, 0, 'What\'s going on? You gonna get me out of here?', 0), -- Two-Tusk Takedown
(25609, 6, 6, 0, 0, 'Oh gosh, do you already have all of that sunken treasure?', 25996), -- Sunken Treasure
(25778, 33, 0, 0, 0, 'What\'s this? That is a lot of gold you have there.', 0), -- Fake Gold for Black Gold
(25774, 1, 0, 0, 0, 'Once you return with enough of that pyrite, we\'ll give it a once over with a paint brush, pile it all up on a pallet, and send you back up with it to the chieftain.', 0), -- Fool's Gold
(25756, 6, 0, 0, 0, 'Do you have the Horde\'s proposal? What are they offering for the drilling rights?', 0), -- Get Zherin!
(25515, 274, 0, 0, 0, 'I\'m not punching the timecard on this one until you get me everything that\'s on that parts list.', 0), -- Down in the Deeps
(25524, 0, 0, 0, 0, 'Oh, for the love of the Light, do you have that crowbar yet? Drowning here!', 25996), -- In the Outhouse
(25504, 6, 0, 0, 0, 'Is that the list of parts, finally? I\'ve been waiting all day for that!', 0), -- Do Me a Favor?
(29032, 1, 0, 0, 0, 'We must get the saber cubs while they\'re still young enough to bond with people. If they get too old, the cats will remain feral forever.', 0), -- Get Them While They're Young
(28523, 0, 1, 0, 0, 'You\'ve certainly earned my trust, $n, but you may need to continue to earn the trust of my untrusting tribe.  There is something you can do to earn that trust.$B$BThe Winterfall are known to carry spirit beads to ward against foul spirits.  These beads have clearly failed in their purpose, as the Winterfall themselves are the agents of corruption.  Bring to me these spirit beads from fallen Winterfall furbolgs; for every set of five you bring me, you will earn recognition amongst the Timbermaw.', 0), -- More Beads for Salfa
(13644, 0, 33, 0, 0, 'The harbinger yet lives, $n. I cannot begin to cleanse Lake Falathim until it is slain.', 25996), -- That Which Has Risen
(13506, 6, 0, 0, 0, 'Yes, $c?', 0), -- Reason to Worry
(13596, 0, 0, 0, 0, 'Have you obtained the plans yet, $n?', 0), -- Twilight Plans
(13591, 0, 0, 0, 0, 'You\'re back! I hear the battle went well.', 0), -- Disturbing Connections
(13569, 0, 0, 0, 0, 'The great spirits have been here longer than I can remember. They were once mortal animals if all the stories are true, and they died in time of dire fates.', 25996), -- The Ritual Bond
(28529, 6, 0, 0, 0, 'How can I help you, $c?', 0), -- Writings of the Void
(25451, 6, 0, 0, 0, 'What\'s this, $n - you\'ve got something special for me?', 0), -- Pristine Yeti Hide
(26401, 0, 0, 0, 0, 'You\'re back... and without him...', 0), -- Return to Vestia
(25394, 0, 1, 0, 0, 'A dragon corrupted is a terrible threat. This must be done!', 25996), -- More Than Illness
(27429, 1, 0, 0, 0, 'Have you put that torch to good use?', 0), -- Raze Direhorn Post!
(27242, 1, 0, 0, 0, 'Did you capture those raptors?', 0), -- Raptor Captor
(27427, 1, 0, 0, 0, 'Did you get those weapons from Blackhoof Village?', 0), -- Arms of the Grimtotems
(27426, 1, 0, 0, 0, 'Were you able to find any trace of the orders?', 0), -- Confirming the Suspicion
(27284, 6, 0, 0, 0, 'Something for me to look at?', 0), -- The Black Shield
(27263, 6, 0, 0, 0, 'Have you found anything of interest at the Shady Rest Inn?', 0), -- Lieutenant Paval Reethe
(27252, 6, 0, 0, 0, 'Have you found evidence from the site of the Shady Rest Inn?', 0), -- The Black Shield
(27247, 0, 0, 0, 0, 'You have something for me?', 0), -- Captain Vimes
(27246, 0, 0, 0, 0, 'Do you have a report to make?', 0), -- The Orc Report
(27237, 1, 0, 0, 0, 'Did your search of the wreckage reveal anything about the Defias cargo?', 0), -- Recover the Cargo!
(27236, 1, 0, 0, 0, 'Let\'s see what you managed to \"borrow\" from the Defias.', 0), -- Secondhand Diving Gear
(27235, 1, 0, 0, 0, 'Well met, $c. What brings you out here?', 0), -- Renn McGill
(27234, 1, 1, 0, 0, 'Were you able to track down their leader?', 25996), -- Defias in Dustwallow?
(27212, 1, 0, 0, 0, 'I thought I heard laughter coming from the barracks. Did you distribute those leaflets I gave you?', 0), -- Discrediting the Deserters
(27220, 1, 0, 0, 0, 'Remember, the deal is \"don\'t come back until something bites you.\"', 0), -- Nat's Bargain
(27211, 1, 0, 0, 0, 'Did you manage to find and capture the remaining propaganda leaflets?', 0), -- Propaganda War
(27218, 1, 0, 0, 0, 'What\'ll it be today? The snook is quite good.', 0), -- Dastardly Denizens of the Deep
(27217, 1, 1, 0, 0, 'Were you able to get any of that thresher oil?', 25996), -- Thresher Oil
(27210, 0, 1, 0, 0, 'Have you driven the deserter agents from Theramore?', 25996), -- Traitors Among Us
(28398, 0, 1, 0, 0, 'Have you managed to capture the pyromancer\'s grimoire?', 0), -- The Pyromancer's Grimoire
(24597, 0, 0, 0, 0, 'Well met, $c. Did you have something for me?', 0), -- A Gift for the King of Stormwind
(27103, 0, 1, 0, 0, 'With the Sealed Reliquary of Purity in our possession, it will be possible not only to remove a corrupting threat from the world but also to study it under our judicious watch.  Perhaps we can even devise new means to combat the taint of corruption that ever threatens Azeroth.', 0); -- Shards of the Felvine

UPDATE `quest_request_items` SET `CompletionText`='<Marley\'s breathing is ragged, coming and going in shuddering gasps.>$B$B<His eyes look at you imploringly.>' WHERE `ID`=25151; -- He Needs Ale!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='How\'s the situation down there?$B$BWhen the raid started I popped a bullet into their ringleader, Stonespire, but they just kept right on coming.' WHERE `ID`=25106; -- Hands Off Me Dig!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25087; -- Report to Twinbraid
UPDATE `quest_request_items` SET `EmoteOnComplete`=273 WHERE `ID`=25080; -- Batteries Not Yet Included
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Do you have a keg of Blast-O powder yet?$B$BWhen you get one ... don\'t shake it.' WHERE `ID`=25079; -- Powder Play
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25075; -- Pick-a-Part
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='How goes the fight, $n?' WHERE `ID`=25082; -- Working the Bugs Out
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25059; -- The Taurajo Briefs
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25057; -- Clap 'Em In Irons
UPDATE `quest_request_items` SET `CompletionText`='<Trawley licks his lips, barely able to constrain his drool.>$B$BYou get my steaks yet? Nice and bloody?' WHERE `ID`=25042; -- Marching On Our Stomachs
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25044; -- Diplomacy By Another Means
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25027; -- You Flicked a Fine Vine to Leaf Me
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25028; -- Trouble From the Ground Up
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='I should mention, you\'re probably going to need a machete to hack through this mess.$B$BThis jungle came out of nowhere!' WHERE `ID`=25015; -- Make 'em Squeal
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=25002; -- Scavenged
UPDATE `quest_request_items` SET `CompletionText`='Burn it all, $C. Burn it to cinders!' WHERE `ID`=24948; -- Lifting the Siege
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=24944; -- Back in the Fight
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25848; -- Downfall
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25846; -- Grundig Darkcloud, Chieftain of the Grimtotem
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25844; -- Sating the Savage Beast
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=25837; -- A Proper Peace Offerin'
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25934; -- World First: Gnomegen
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `CompletionText`='Hurry, $n, the pups are hungry!' WHERE `ID`=25935; -- Hungry Pups
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25912; -- Seen Better Days
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='Recover the sentinel\'s glaives, $n. Each glaive is unique to a sentinel.' WHERE `ID`=25913; -- Putting Them to Rest
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25876; -- It's Up There!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25767; -- Capturing Memories
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=25673; -- Just Ask Alice
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25730; -- BEWARE OF CRAGJAW!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25650; -- Orders from High Command
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25649; -- Minx'll Fix It
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=25642; -- Don't Look Them in the Eyes
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=28395; -- Feathers for Nafien
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `VerifiedBuild`=25996 WHERE `ID`=28396; -- Feathers for Grazle
UPDATE `quest_request_items` SET `EmoteOnComplete`=51, `CompletionText`='$n, you have returned.' WHERE `ID`=13796; -- The Forest Heart
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='Our night elf scouts report that preparations for the attack are almost complete. Those dreadlords must die soon, $n!' WHERE `ID`=26445; -- Never Again!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26443; -- Diabolical Plans
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Time\'s running out, $n.', `VerifiedBuild`=25996 WHERE `ID`=13698; -- Explosives Shredding
UPDATE `quest_request_items` SET `EmoteOnComplete`=51 WHERE `ID`=13869; -- Recover the Remains
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26454; -- A Shameful Waste
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26468; -- The Branch of Cenarius
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='Can you feel it, $n, the touch of corruption upon the wind? If we do nothing, it will continue to advance. That is why I seek the Chalice of Elune. Were you able to find it?' WHERE `ID`=26455; -- The Lost Chalice
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26456; -- Report from the Northern Front
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='You return, $n. What\'s that affixed to the top of the rod? A skull?' WHERE `ID`=26482; -- True Power of the Rod
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13979; -- The Goblin Braintrust
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25607; -- Ze Gnomecorder
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Yes, $n? How go your efforts?' WHERE `ID`=26479; -- Return to Raene
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='$n, is that you? Have you returned with the cure for Relara?' WHERE `ID`=13924; -- All's Well
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='Did you find the final piece of the rod, $n? How did my technique work?', `VerifiedBuild`=25996 WHERE `ID`=26478; -- Playing Possum
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13922; -- In the Hands of the Perverse
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26477; -- Search the Bole
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13928; -- Recover the Fallen
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26476; -- Dryad Delivery
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13874; -- A Not-So-Charmed Life
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13876; -- Too Far Gone
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13868; -- Corrupting Influence?
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='$n, did you find the remains of the lake?  Do you have the Tear?' WHERE `ID`=26475; -- Elune's Tear
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26474; -- Orendil's Cure
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13645; -- To Raene Wolfrunner
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13642; -- Bathed in Light
UPDATE `quest_request_items` SET `EmoteOnComplete`=2, `CompletionText`='Ah, welcome back, $n.' WHERE `ID`=26464; -- The Lost Gem
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13626; -- Respect for the Fallen
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13623; -- Delivery for Orendil
UPDATE `quest_request_items` SET `CompletionText`='It is said that the Ring of Zoram is the key to any lock within the city. Do you have it, $n?' WHERE `ID`=26466; -- Ruuzel
UPDATE `quest_request_items` SET `CompletionText`='Have you found many statuettes, $n?' WHERE `ID`=26465; -- The Ancient Statuettes
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Have you gathered the Bathran\'s Hair, $n?  The child\'s health grows weaker by the hour....' WHERE `ID`=26473; -- Bathran's Hair
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13891; -- The Devourer of Darkshore
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnCompleteDelay`=50 WHERE `ID`=13882; -- The Seeds of Life
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13544; -- The Bear's Blessing
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13526; -- The Bear's Paw
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnCompleteDelay`=100 WHERE `ID`=13910; -- A New Home
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnCompleteDelay`=50 WHERE `ID`=13918; -- The Titans' Terminal
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13912; -- Swamped Secrets
UPDATE `quest_request_items` SET `CompletionText`='Did you find it, $n?' WHERE `ID`=13587; -- The Waking Nightmare
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13558; -- Call Down the Thunder
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13590; -- The Front Line
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13513; -- On the Brink
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13505; -- Remnants of the Highborne
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13563; -- A Love Eternal
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13566; -- Ritual Materials
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13598; -- Unsavory Remedies
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=13554; -- A Cure In The Dark
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnCompleteDelay`=200 WHERE `ID`=13831; -- A Troubling Prescription
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13557; -- Bearer of Good Fortune
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13527; -- No Accounting for Taste
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13520; -- The Boon of the Seas
UPDATE `quest_request_items` SET `CompletionText`='No offense to whoever Nijel is, but this camp ain\'t the most comfortable place I\'ve spent a night, if you know what I mean, $n.' WHERE `ID`=1456; -- The Karnitol Shipwreck
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='How goes the hunt, $n?  Are you here to report your success?' WHERE `ID`=25429; -- Zukk'ash Infestation
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=25426; -- War on the Woodpaw
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=25450; -- Improved Quality
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID`=25449; -- The Mark of Quality
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=25458; -- General Skessesh
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID`=25447; -- Signs of Change
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=29691; -- Bring Me A Shrubbery!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=29567; -- Stalk the Stalker
UPDATE `quest_request_items` SET `CompletionText`='My research with the Mudrock tongues is progressing nicely.  I trust your crab hunt goes well?' WHERE `ID`=1258; -- ... and Bugs
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1204; -- Mudrock Soup and Bugs
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Salutations, $n.  Do try to avoid stepping on my pant cuffs.  This outfit is newly tailored.' WHERE `ID`=543; -- The Perenolde Tiara
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=27070; -- A Fool's Errand
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='My rogues need to hone their lockpicking skills, and I need locks of adequate difficulty -- the stuff Zan makes us is unfit for all but the lowliest neophytes.$b$bTell ya what, if you bring me 5 Heavy Junkboxes, I\'ll put in a good word for you around here.$b$bYou can unlock the boxes and rifle through them, but you\'ll have to leave at least a few coins in them... even a rogue in training needs motivation.' WHERE `ID`=8249; -- Junkboxes Needed
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26528; -- The Eye of Shadra
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='You appear to have uncovered the wreckage of... a robotic chicken?  The voice from within the egg crackles to life again:$B$B\"Yes, excellent work!  This is indeed my homing robot, though my sensors indicate that it needs a jump start before it can fly back to Booty Bay for repairs.  Go ahead and place the beacon inside the rover - the beacon will take care of the rest!\"' WHERE `ID`=485; -- Find OOX-09/HL!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=27105; -- An Unwelcome Guest
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='$n, you have stupid elf\'s web?' WHERE `ID`=27108; -- Lethtendris's Web
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=27107; -- Pusillin The Thief
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26524; -- Dark Vessels
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26492; -- Skulk Rock Supplies
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26490; -- Prime Slime
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26485; -- Snapjaws, Lad!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26873; -- Preemptive Methods
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26872; -- Deviate Hides

UPDATE `quest_request_items` SET `VerifiedBuild`=25996 WHERE `ID` IN (24941, 13582);

DELETE FROM `quest_request_items` WHERE `ID` IN (37445 /*Spare Parts*/, 37444 /*Inoculation*/, 25421 /*The Grand Tablet*/, 25565 /*Fragments of Language*/, 25065 /*You Too, Brute?*/, 25063 /*Terrapination*/, 25062 /*What We Came For*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(37445, 1, 0, 0, 0, 'When we have those spare parts, I know that we\'ll get this emitter repaired. With any luck there will be someone else out there left to talk to.', 0), -- Spare Parts
(37444, 1, 0, 0, 0, 'The more we can do to clear up Nestlewood, the faster Zhanaa can get back to work.', 0), -- Inoculation
(25421, 0, 0, 0, 0, 'You\'re back! What have you found?', 0), -- The Grand Tablet
(25565, 0, 0, 0, 0, 'Do you have the tablets?', 0), -- Fragments of Language
(25065, 0, 0, 0, 0, 'Do be careful with the contents of the chest.', 0), -- You Too, Brute?
(25063, 0, 0, 0, 0, 'Hopefully your spree of turtle destruction left it intact.', 0), -- Terrapination
(25062, 0, 0, 0, 0, 'What have you found?', 0); -- What We Came For

UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `CompletionText`='Those stalkers cleared out yet?   We\'ve had a few of our people who headed north disappear.$B$BIf it\'s because of the stalkers, I want to make sure that it doesn\'t happen again.', `VerifiedBuild`=26124 WHERE `ID`=10620; -- Ridgespine Menace
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Don\'t worry, $n!  Worry never got anyone anywhere!', `VerifiedBuild`=26124 WHERE `ID`=10710; -- Test Flight: The Singing Ridge
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='You have them?  You have the three drake essences that I so dearly need to continue my research?$B$BYou know that those nether drake eggs used to be black dragon eggs?  It\'s a fact!  But when Draenor blew apart, the resultant nether that raced across what was left mutated the eggs.', `VerifiedBuild`=26124 WHERE `ID`=10609; -- What Came First, the Drake or the Egg?
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Don\'t be afraid!  This is for science, and science is painful!', `VerifiedBuild`=26124 WHERE `ID`=10557; -- Test Flight: The Zephyrium Capacitorium
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10584; -- Picking Up Some Power Converters
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='What brings you to me?  Surely not more trouble with the Bloodmaul ogre clan?' WHERE `ID`=10518; -- Planting the Banner
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10516; -- The Trappings of a Vindicator
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Any luck out there?  I know that it\'s dangerous work to be doing this amongst the Bloodmaul ogres, but if we can avoid the killing of any more animals, I\'ll be happy.' WHERE `ID`=10506; -- A Dire Situation
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='How fares the bolstering of the Living Grove\'s defenses?$B$BWith the intentions of the arakkoa at Veil Lashh unknown, and the Horde just on the other side of the ravine, I fear that if we do not move quickly we will find ourselves in a poor situation to protect our new home and our work in the grove.', `VerifiedBuild`=26124 WHERE `ID`=10457; -- Protecting Our Own
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `CompletionText`='Bloodmaul or Bladespire, it doesn\'t matter.  All of the ogre clans fight against each other, vying for the dominance that comes with having the favor of Gruul the Dragonkiller.$B$BEach is still our enemy, regardless of who that favor has fallen to.', `VerifiedBuild`=26124 WHERE `ID`=10504; -- The Bladespire Ogres
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='What\'s the word?  Are the Bladespire ogres as indiscriminate as the Bloodmaul, or did it nearly kill them like it did me?', `VerifiedBuild`=26124 WHERE `ID`=10512; -- Getting the Bladespire Tanked
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='I cannot stress strongly enough the need for those Thunderlord dire wolves to be dealt with.  Their very existence endangers the stability of the Living Grove and all of our work here.', `VerifiedBuild`=26124 WHERE `ID`=10456; -- Marauding Wolves
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10555; -- Malaise
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10511; -- Strange Brew
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10510; -- Into the Draenethyst Mine
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10690; -- The Den Mother
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10502; -- The Bloodmaul Ogres
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `CompletionText`='Did I not speak the truth?  The grovestalker lynxes have become a menace not only to those who would travel the path here, but also to Sylvanaar itself.$B$BTheir deaths are regrettable, but the whole point of our creation of the Living Grove is so that Sylvanaar can be surrounded by a defensive region of natural beauty and tranquility.', `VerifiedBuild`=26124 WHERE `ID`=10455; -- The Encroaching Wilderness
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='There\'s no shame in admitting that you haven\'t the spine to hunt the mightiest of animals this land has to offer, $n.' WHERE `ID`=9852; -- The Ultimate Bloodsport
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9856; -- Windroc Mastery
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=26124 WHERE `ID`=9789; -- Clefthoof Mastery
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=26124 WHERE `ID`=9857; -- Talbuk Mastery
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=26124 WHERE `ID`=9854; -- Windroc Mastery
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9871; -- Murkblood Invaders
UPDATE `quest_request_items` SET `CompletionText`='Have you retrieved the crystal fragments I asked of you, $n?' WHERE `ID`=9882; -- Stealing from Thieves
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10011; -- Forge Camp: Annihilated
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10004; -- Patience and Understanding
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=10001; -- The Master Planner
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=26124 WHERE `ID`=9999; -- Buying Time
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=9962; -- The Ring of Blood: Brokentoe
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9933; -- Message to Telaar
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9932; -- Body of Evidence
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9931; -- Returning the Favor
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9956; -- The Ravaged Caravan
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=9928; -- Armaments for Deception
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='<Lantresor\'s eyes open in bewilderment.>$B$BIs it done?' WHERE `ID`=9927; -- Ruthless Cunning
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=9917; -- Do My Eyes Deceive Me
UPDATE `quest_request_items` SET `CompletionText`='Well, $n?  Are you all talk or do you have something to show me?' WHERE `ID`=10476; -- Fierce Enemies
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `CompletionText`='Did I mention my love for eggs?' WHERE `ID`=10111; -- Bring Me The Egg!
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='The book, $n.  Have you obtained it?' WHERE `ID`=11029; -- A Shabby Disguise
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='You\'ve returned, $n.  I was beginning to think you\'d given up on me.' WHERE `ID`=11056; -- Hazzik's Bargain
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=11093; -- Hungry Nether Rays
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you obtained the dust, $n?' WHERE `ID`=11004; -- World of Shadows
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10923; -- Evil Draws Near
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10877; -- The Dread Relic
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=10929; -- Fumping
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10030; -- Recover the Bones
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10839; -- Veil Skith: Darkstone of Terokk
UPDATE `quest_request_items` SET `EmoteOnComplete`=396 WHERE `ID`=10849; -- Seek Out Kirrik
UPDATE `quest_request_items` SET `EmoteOnComplete`=396 WHERE `ID`=10847; -- The Eyes of Skettis
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you retrieved the relics, $n?  We cannot allow the Shadow Council to use their power for dark purposes.' WHERE `ID`=10881; -- The Shadow Tomb
UPDATE `quest_request_items` SET `CompletionText`='You wish to show me something, $n?' WHERE `ID`=10880; -- Cabal Orders
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you done what I asked of you, $n?  I fear for our lives.', `VerifiedBuild`=26124 WHERE `ID`=10878; -- Before Darkness Falls
UPDATE `quest_request_items` SET `CompletionText`='What is it you have there, $n?' WHERE `ID`=10012; -- Fel Orc Plans
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10007; -- Thinning the Ranks
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10035; -- Torgos!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9994; -- What Are These Things?
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `CompletionText`='It\'s good to see you again, $n. Have you done as I asked?', `VerifiedBuild`=26124 WHERE `ID`=9986; -- Stymying the Arakkoa
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10016; -- Timber Worg Tails
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='What news do you bring, $n?' WHERE `ID`=9990; -- Investigate Tuurem
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10112; -- A Personal Favor
UPDATE `quest_request_items` SET `CompletionText`='Does $n have hides for Maktu?' WHERE `ID`=9834; -- Natural Armor
UPDATE `quest_request_items` SET `CompletionText`='What news do you bring, $n?' WHERE `ID`=9731; -- Drain Schematics
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9709; -- Stealing Back the Mushrooms
UPDATE `quest_request_items` SET `CompletionText`='You\'re back, $n.  Did you obtain the fertile spores?', `VerifiedBuild`=26124 WHERE `ID`=9806; -- Fertile Spores
UPDATE `quest_request_items` SET `CompletionText`='You\'ve something to show me, $n?' WHERE `ID`=9919; -- Sporeggar
UPDATE `quest_request_items` SET `CompletionText`='What is it you have there, $n?' WHERE `ID`=9827; -- Withered Basidium
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=9896; -- Blacksting's Bane
UPDATE `quest_request_items` SET `CompletionText`='Hail, $n.' WHERE `ID`=9718; -- As the Crow Flies
UPDATE `quest_request_items` SET `CompletionText`='Did you find my belongings, $n?  The cave is not far from Umbrafen, near the border with Nagrand.', `VerifiedBuild`=26124 WHERE `ID`=9788; -- A Damp, Dark Place
UPDATE `quest_request_items` SET `CompletionText`='Did you find any plant parts, $n?' WHERE `ID`=9802; -- Plants of Zangarmarsh
UPDATE `quest_request_items` SET `CompletionText`='It\'s good to see you again, $n.  How\'s your hunt for the naga going?' WHERE `ID`=9728; -- A Warm Welcome
UPDATE `quest_request_items` SET `CompletionText`='Have you seen the vision yet, $n?' WHERE `ID`=9545; -- The Seer's Relic
UPDATE `quest_request_items` SET `CompletionText`='Did you retrieve the Sha\'naar relics, $n?' WHERE `ID`=9430; -- Sha'naar Relics
UPDATE `quest_request_items` SET `CompletionText`='Is it done, $n?  Is Arzeth dead?' WHERE `ID`=10369; -- Arzeth's Demise
UPDATE `quest_request_items` SET `CompletionText`='Tell me, $n.  Have the Dreghood elders been released?' WHERE `ID`=10368; -- The Dreghood Elders
UPDATE `quest_request_items` SET `CompletionText`='Did you obtain the key, $n?' WHERE `ID`=10367; -- A Traitor Among Us
UPDATE `quest_request_items` SET `CompletionText`='You return, $n.  Are the waters cleansed?' WHERE `ID`=9427; -- Cleansing the Waters
UPDATE `quest_request_items` SET `CompletionText`='Did you bring back proof of Blacktalon\'s death, $n?' WHERE `ID`=9490; -- The Rock Flayer Matriarch
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10629; -- Shizz Work
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10236; -- Outland Sucks!
UPDATE `quest_request_items` SET `CompletionText`='The fel spirits of the Shattered Hand orcs are a blight to poor Jules\' soul.  Tell me, $n... has he been appeased?' WHERE `ID`=10909; -- Fel Spirits
UPDATE `quest_request_items` SET `CompletionText`='Do you have the talismans, $n?  It pains me to know that those cursed orcs possess our soldiers insignias...' WHERE `ID`=10484; -- Cursed Talismans
UPDATE `quest_request_items` SET `CompletionText`='You close down that war-portal yet, $n? While you\'re here shuffling your feet, there are more demons entering Outland! \n' WHERE `ID`=10397; -- Invasion Point: Annihilator
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=10346; -- Return to the Abyssal Shelf
UPDATE `quest_request_items` SET `CompletionText`='This is a vital mission, $n.  It\'s one I would not trust to just anyone.', `VerifiedBuild`=26124 WHERE `ID`=10146; -- Mission: The Murketh and Shaadraz Gateways
UPDATE `quest_request_items` SET `CompletionText`='Do not mourn their demise, $n.' WHERE `ID`=9682; -- The Hopeless Ones...
UPDATE `quest_request_items` SET `CompletionText`='Don\'t drink the water, $n!' WHERE `ID`=9748; -- Don't Drink the Water
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9699; -- Truth or Fiction
UPDATE `quest_request_items` SET `CompletionText`='<Velen smiles.>$B$BGreetings, $n. I have been expecting you.' WHERE `ID`=9698; -- Audience with the Prophet
UPDATE `quest_request_items` SET `CompletionText`='What have you got there, $n? Is that a journal?' WHERE `ID`=9706; -- Galaen's Journal - The Fate of Vindicator Saruan
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9550; -- A Map to Where?
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9779; -- Intercepting the Message
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9629; -- Catch and Release
UPDATE `quest_request_items` SET `CompletionText`='How goes the hunt, $n?' WHERE `ID`=9580; -- The Bear Necessities
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9623; -- Coming of Age
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=9602; -- Deliver Them From Evil...
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9537; -- Show Gnomercy
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID`=9523; -- Precious and Fragile Things Need Special Handling
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9506; -- A Small Start
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9571; -- The Kurken's Hide
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9570; -- The Kurken is Lurkin'
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9560; -- Beasts of the Apocalypse!
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9562; -- Murlocs... Why Here? Why Now?
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9564; -- Gurf's Dignity
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9453; -- Find Acteon!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9798; -- Blood Elf Plans
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9799; -- Botanical Legwork
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9409; -- Urgent Delivery!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Have you harvested the necessary moth blood for the healing crystals yet?  With survivors scattered all over the vale, time is of the essence!' WHERE `ID`=9369; -- Replenishing the Healing Crystals
UPDATE `quest_request_items` SET `EmoteOnComplete`=274 WHERE `ID`=8308; -- Brann Bronzebeard's Lost Letter
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you retrieved the phylactery yet, $n?' WHERE `ID`=10947; -- An Artifact From the Past
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Is the deed done, $n?  Illidan is not a patient master!' WHERE `ID`=10946; -- Ruse of the Ashtongue
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=11007; -- Kael'thas and the Verdant Sphere
UPDATE `quest_request_items` SET `CompletionText`='Have you completed what I asked of you, $n?', `VerifiedBuild`=26124 WHERE `ID`=10692; -- Varedis Must Be Stopped
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=29641; -- The Soul Devices
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you obtained the book, $n?  ', `VerifiedBuild`=26124 WHERE `ID`=10649; -- The Book of Fel Names
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10669; -- Against All Odds
UPDATE `quest_request_items` SET `CompletionText`='It is dirty work, $n.' WHERE `ID`=11020; -- A Slow Death
UPDATE `quest_request_items` SET `CompletionText`='Dead orcs tell no tales, $n. Make sure those Dragonmaw transporters do not escape.' WHERE `ID`=11035; -- The Not-So-Friendly Skies...
UPDATE `quest_request_items` SET `EmoteOnComplete`=388 WHERE `ID`=11041; -- A Job Unfinished...
UPDATE `quest_request_items` SET `CompletionText`='We don\'t need those eggs to get into the wrong hands, $n. Bring me any additional eggs that you may find.$B$BJust remember to keep a low profile and avoid raising suspicion!', `VerifiedBuild`=26124 WHERE `ID`=11050; -- Accepting All Eggs
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11049; -- The Great Netherwing Egg Hunt
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='<Karynaku groans.>', `VerifiedBuild`=26124 WHERE `ID`=10872; -- Zuluhed the Whacked
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='<A\'dal notices your approach and a warm light embraces you.  A\'dal seems to know you have something for him.>' WHERE `ID`=11052; -- Akama's Promise
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='You\'ve returned, $n.' WHERE `ID`=10707; -- The Ata'mal Terrace
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you obtained the four medallion fragments, $n?', `VerifiedBuild`=26124 WHERE `ID`=10685; -- The Ashtongue Corruptors
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Hail, $n.  What news do you bring?', `VerifiedBuild`=26124 WHERE `ID`=10817; -- The Great Retribution
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Any news yet, $n?  Time is not on our side.', `VerifiedBuild`=26124 WHERE `ID`=10684; -- Oronu the Elder
UPDATE `quest_request_items` SET `CompletionText`='Have you found the tablets yet, $n?', `VerifiedBuild`=26124 WHERE `ID`=10683; -- Tablets of Baa'ri
UPDATE `quest_request_items` SET `CompletionText`='Have you completed the task I asked of you, $n?', `VerifiedBuild`=26124 WHERE `ID`=10687; -- Karabor Training Grounds
UPDATE `quest_request_items` SET `CompletionText`='How fares the battle against Kael\'s forces?', `VerifiedBuild`=26124 WHERE `ID`=10823; -- More Sunfury Signets
UPDATE `quest_request_items` SET `CompletionText`='Even the smallest contribution to our cause is noted, $n.  Our enemies are many, but we shall prevail!', `VerifiedBuild`=26124 WHERE `ID`=10822; -- Single Sunfury Signet
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Go on, $n.  Speak.' WHERE `ID`=10824; -- Sunfury Signets
UPDATE `quest_request_items` SET `CompletionText`='Have you completed the task I requested of you, $n?', `VerifiedBuild`=26124 WHERE `ID`=10807; -- The Ashtongue Broken
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10588; -- The Cipher of Damnation
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `CompletionText`='$n!' WHERE `ID`=10579; -- The Cipher of Damnation - The Third Fragment Recovered
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10541; -- The Cipher of Damnation - The Second Fragment Recovered
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10523; -- The Cipher of Damnation - The First Fragment Recovered
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=26124 WHERE `ID`=10578; -- The Cipher of Damnation - Borak's Charge
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=26124 WHERE `ID`=10577; -- What Illidan Wants, Illidan Gets...
UPDATE `quest_request_items` SET `CompletionText`='It\'s far too complicated, $r. You wouldn\'t understand.' WHERE `ID`=10576; -- The Shadowmoon Shuffle
UPDATE `quest_request_items` SET `CompletionText`='Be quick about it, $g boy:girl;.' WHERE `ID`=10570; -- To Catch A Thistlehead
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10550; -- The Bundle of Bloodthistle
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=10547; -- Of Thistleheads and Eggs...
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=26124 WHERE `ID`=10540; -- The Cipher of Damnation - Ar'tor's Charge
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10537; -- Lohn'goron, Bow of the Torn-heart
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=26124 WHERE `ID`=10528; -- Demonic Crystal Prisons
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10522; -- The Cipher of Damnation - Grom'tor's Charge
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=10514; -- I Was A Lot Of Things...
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10481; -- Enraged Spirits of Air
UPDATE `quest_request_items` SET `CompletionText`='Is it done, $n? Have you stopped the dark conclave from completing their ritual?' WHERE `ID`=10808; -- Thwart the Dark Conclave
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10612; -- The Fel and the Furious
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10606; -- The Art of Fel Reaver Maintenance
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10480; -- Enraged Spirits of Water
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=10776; -- Dissension Amongst the Ranks...
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10678; -- The Main Course!
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `CompletionText`='I hope you\'ve done somethin\' special, $g lad:lass;. Otherwise, buzz off!\n' WHERE `ID`=10648; -- Wanted: Uvuros, Scourge of Shadowmoon
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10636; -- Divination: Gorefiend's Truncheon
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10782; -- Imbuing the Headpiece
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10775; -- Tabards of the Illidari
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10793; -- The Journal of Val'zareq: Portends of War
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10774; -- Blood Elf + Giant = ???
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10780; -- Sketh'lon Feathers
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10773; -- Breaching the Path
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='We must find a way to destroy the rest of those infernals, $n. We\'ve come far, but failure could still cost us everything.', `VerifiedBuild`=26124 WHERE `ID`=10589; -- Gaining Access
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10582; -- Minions of the Shadow Council
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10564; -- Blast the Infernals!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10572; -- Setting Up the Bomb
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10563; -- To Legion Hold
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10778; -- The Rod of Lianthe
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10777; -- Asghar's Totem
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='What brings you here, $c? I don\'t get many visitors.' WHERE `ID`=10662; -- The Hermit Smith
UPDATE `quest_request_items` SET `EmoteOnComplete`=273 WHERE `ID`=10643; -- Harbingers of Shadowmoon
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10677; -- The Second Course...
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10626; -- Capture the Weapons
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10642; -- A Ghost in the Machine
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10621; -- Illidari-Bane Shard
UPDATE `quest_request_items` SET `EmoteOnComplete`=4, `EmoteOnIncomplete`=4, `VerifiedBuild`=26124 WHERE `ID`=10661; -- Spleendid!
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10562; -- Besieged!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10569; -- The Sketh'lon Wreckage
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Is it done, $n?' WHERE `ID`=10507; -- Turning Point
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='<The musical tinkling of the naaru\'s speech fills your mind.>$B$BI sense that you have something of great power with you, $r.  What is it that you bring to me?' WHERE `ID`=10280; -- Special Delivery to Shattrath City
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='Hello again, my friend.  How fare your efforts to find the crystal?' WHERE `ID`=10276; -- Full Triangle
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10275; -- Triangulation Point Two
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=26124 WHERE `ID`=10273; -- Troublesome Distractions
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='Are you prepared to discuss business now, $n?' WHERE `ID`=10270; -- A Not-So-Modest Proposal
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10971; -- Ethereum Secrets
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10970; -- A Mission of Mercy
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10438; -- On Nethery Wings
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10408; -- Nexus-King Salhadaar
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10385; -- Potential for Brain Damage = High
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10384; -- Ethereum Data
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='Hello, traveler.  You come to Hazzin because you are in need of my goods?' WHERE `ID`=10269; -- Triangulation Point One
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10345; -- The Flesh Lies...
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10437; -- Recipe for Destruction
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10422; -- Captain Tyralius
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10411; -- Electro-Shock Goodness!
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you obtained Socrethar\'s teleportation stone, $n?' WHERE `ID`=10508; -- A Gift for Voren'thal
UPDATE `quest_request_items` SET `CompletionText`='Is it done then?  Are the teleporters shut down?' WHERE `ID`=10857; -- Teleport This!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10293; -- Hitting the Motherlode
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10430; -- Testing the Prototype
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10429; -- When Nature Goes Too Far
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10427; -- Creatures of the Eco-Domes
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10290; -- In Search of Farahlite
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10424; -- Diagnosis: Critical
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10426; -- Flora of the Eco-Domes
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10268; -- An Audience with the Prince
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10435; -- Retrieving the Goods
UPDATE `quest_request_items` SET `CompletionText`='Did you try out my little experiment, $n?', `VerifiedBuild`=26124 WHERE `ID`=10855; -- Fel Reavers, No Thanks!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10336; -- The Minions of Culuthas
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `CompletionText`='That was fast.  You must be a very efficient person to have placed all three of those markers already.', `VerifiedBuild`=26124 WHERE `ID`=10335; -- Surveying the Ruins
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10432; -- Damning Evidence
UPDATE `quest_request_items` SET `CompletionText`='Have you completed the task I asked of you, $n?' WHERE `ID`=10365; -- Shutting Down Manaforge Ara
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Did you complete the shut down?  You should hurry before I change my mind about the whole deal.' WHERE `ID`=10338; -- Shutting Down Manaforge Duro
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10248; -- You, Robot
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10924; -- Bloody Imp-ossible!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10235; -- Declawing Doomclaw
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `CompletionText`='<Shauly raises his voice so as to catch the attention of the ethereals in the area.>$B$BHave any pelts to sell me?', `VerifiedBuild`=26124 WHERE `ID`=10433; -- Keeping Up Appearances
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10348; -- New Opportunities
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10417; -- Run a Diagnostic!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10234; -- One Demon's Trash...
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10267; -- Rightful Repossession
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='Have you activated all the runes? I\'m eager to see if we can\'t improve upon the blood elf method here. Anything one of Kael\'thas\'s men can do, real Kirin Tor can do better.' WHERE `ID`=10240; -- Building a Perimeter
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10319; -- Capturing the Phylactery
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='What have you discovered, $n?' WHERE `ID`=10314; -- A Lingering Suspicion
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10209; -- Summoner Kanthin's Prize
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='What have you found, $n?', `VerifiedBuild`=26124 WHERE `ID`=10307; -- Cohlien Frostweaver
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='What have you found, $n?', `VerifiedBuild`=26124 WHERE `ID`=10305; -- Abjurist Belmara
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `CompletionText`='Is it done, $n? Have you avenged the fallen of Kirin\'Var Village?', `VerifiedBuild`=26124 WHERE `ID`=10222; -- The Sunfury Garrison
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10312; -- The Annals of Kirin'Var
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10239; -- Potential Energy Source
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10343; -- The Unending Invasion
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10331; -- Indispensable Tools
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10334; -- Needs More Cowbell
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10301; -- Unlocking the Compendium
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you completed your task yet, $n?' WHERE `ID`=10330; -- Shutting Down Manaforge Coruu
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='How goes the eavesdropping, $n?  You\'d best hurry.  I\'m getting antsy here.' WHERE `ID`=10198; -- Information Gathering
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=26124 WHERE `ID`=10197; -- A Convincing Disguise
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10308; -- Another Heap of Ethereals
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10199; -- That Little Extra Kick
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Back with their tech so soon?  You better not just be pulling my leg here, $c.$B$BThe success of the X-52 project out here depends upon you getting us that stuff a.s.a.p.!' WHERE `ID`=10206; -- Pick Your Part
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='It\'s over then?  Warp-Raider Nesaad is dead?', `VerifiedBuild`=26124 WHERE `ID`=10205; -- Warp-Raider Nesaad
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='Is it done?  Have you wiped the Zaxxis scum from the face of Outland and brought me their insignia?' WHERE `ID`=10262; -- A Heap of Ethereals
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Did the plan work?  I was half-expecting you to get blown up, to tell you the truth.', `VerifiedBuild`=26124 WHERE `ID`=10329; -- Shutting Down Manaforge B'naar
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='You have the power from those elementals yet?  Oh, don\'t hurry or anything.  It\'s just my life and career on the line.', `VerifiedBuild`=26124 WHERE `ID`=10226; -- Elemental Power Extraction
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='Have you saved us from the depredations of Dr. Boom?  I promise this time there won\'t be any exploding wagons, though that was a lot of fun!$B$BWe really should do that more often.', `VerifiedBuild`=26124 WHERE `ID`=10221; -- Dr. Boom!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10224; -- Essence for the Engines
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Um, hi.   I\'m a little busy here.  What\'s that you have there?' WHERE `ID`=10225; -- Report to Engineering
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10300; -- Rebuilding the Staff
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Did you obtain the items I asked of you, $n?' WHERE `ID`=10189; -- Manaforge B'naar
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='You have enough of that shale yet?  I\'m going to need a lot of it to extract the amount of oil that\'ll be needed for the X-52 Nether Rocket\'s fuel.' WHERE `ID`=10342; -- Securing the Shaleskin Shale
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10265; -- Consortium Crystal Collection
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10186; -- You're Hired!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10190; -- Recharging the Batteries
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10261; -- Wanted: Annihilator Servo!
UPDATE `quest_request_items` SET `EmoteOnComplete`=2, `EmoteOnIncomplete`=2, `VerifiedBuild`=26124 WHERE `ID`=10173; -- The Archmage's Staff
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='My eyesight must be going from all of the nether radiation.  You have that fel reaver\'s heart yet?' WHERE `ID`=10309; -- It's a Fel Reaver, But with Heart
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11059; -- Guardian of the Monument
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11079; -- A Fel Whip For Gahk
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='How fares yer mission, $n?  I needn\'t tell ye how important this be ta our continued ability ta fly around up here.' WHERE `ID`=11078; -- To Rule The Skies
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11023; -- Bomb Them Again!
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `CompletionText`='You\'re doing great work for us, $n.  I want you to know that we really appreciate everything that you\'re doing to keep us stocked up in fresh mounts!' WHERE `ID`=11066; -- Wrangle More Aether Rays!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11065; -- Wrangle Some Aether Rays!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11010; -- Bombing Run
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11030; -- Our Boy Wants To Be A Skyguard Ranger
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='As you come to understand the shards and crystals, you will be better able to assist us in protecting ourselves and our ogre brethren below.$B$BThe shards themselves get their name from an ancient and now-extinct arakkoan civilization, which used to live atop the mountains here.$B$BDo you have the shards with you?', `VerifiedBuild`=26124 WHERE `ID`=11025; -- The Crystals
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11000; -- Into the Soulgrinder
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10998; -- Grim(oire) Business
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10802; -- Gorgrom the Dragon-Eater
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10912; -- The Hound-Master
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10911; -- Fire At Will!
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10904; -- Harvesting the Fel Ammunition
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Did the baron fashion us a trap?  One powerful enough to kill a gronn?' WHERE `ID`=10801; -- It's a Trap!
UPDATE `quest_request_items` SET `CompletionText`='You are before me again, $c.  This must mean that you\'ve procured the sack out from underneath Grulloc\'s nose.' WHERE `ID`=10800; -- Goodnight, Gronn
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='You have all of the venom glands?  If not, begone and waste no more of my time until you do!' WHERE `ID`=10799; -- Into the Churning Gulch
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Hello, $g lad : lass;, what news do you bring?' WHERE `ID`=10797; -- Favor of the Gronn
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10997; -- Even Gronn Have Standards
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10996; -- Maggoc's Treasure Chest
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10995; -- Grulloc Has Two Skulls
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10594; -- Gauging the Resonant Frequency
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `CompletionText`='What news do you bring?  Do you know what the wyrmcultists are up to?', `VerifiedBuild`=26124 WHERE `ID`=10722; -- Meeting at the Blackwing Coven
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10825; -- The Truth Unorbed
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10894; -- Wyrmskull Watcher
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10747; -- Whelps of the Wyrmcult
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10719; -- Did You Get The Note?
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10717; -- Poaching from Poachers
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10796; -- Crush the Bloodmaul Camp!
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10795; -- A Date with Dorgok
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10771; -- From the Ashes
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10567; -- Creating the Pendant
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=10712; -- Test Flight: Ruuan Weald
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10675; -- Show Them Gnome Mercy!
UPDATE `quest_request_items` SET `EmoteOnComplete`=11 WHERE `ID`=10671; -- More than a Pound of Flesh
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10674; -- Trapping the Light Fantastic
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26124 WHERE `ID`=10632; -- Cutting Your Teeth
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26124 WHERE `ID`=10657; -- Ride the Lightning

UPDATE `quest_request_items` SET `VerifiedBuild`=26124 WHERE `ID` IN (9784, 10854, 10836, 10688, 10704, 10850, 10188);

DELETE FROM `quest_request_items` WHERE `ID` IN (12301 /*The Truth Shall Set Us Free*/, 11698 /*Might As Well Wipe Out the Scourge*/, 11694 /*There's Something Going On In Those Caves*/, 11693 /*Oh Great... Plagued Magnataur!*/, 29613 /*A Proper Fate*/, 29615 /*Windcaller Claw and the Water Thief*/, 29654 /*Turning the Tide*/, 29656 /*O'mrogg's Warcloth*/, 29649 /*How to Save a Life*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(12301, 0, 6, 0, 0, 'Is it done?', 26365), -- The Truth Shall Set Us Free
(11698, 0, 1, 0, 0, 'There\'s no way that you could have killed so many Scourge in such a short time!', 26365), -- Might As Well Wipe Out the Scourge
(11694, 0, 1, 0, 0, 'Time\'s wasting, $c. The last thing we need is to have to face plagued magnataur.$B$BThe normal ones are bad enough as it is!', 26365), -- There's Something Going On In Those Caves
(11693, 0, 1, 0, 0, 'Doesn\'t look like enough of the plagued magnataur have been put down yet, $c.$B$BThink you could take care of a few more before coming back?', 26365), -- Oh Great... Plagued Magnataur!
(29613, 0, 0, 0, 0, 'Is Kalithresh dead? Please tell me he didn\'t escape.', 26365), -- A Proper Fate
(29615, 0, 0, 0, 0, 'Did you dispatch of the water thief?', 26365), -- Windcaller Claw and the Water Thief
(29654, 0, 0, 0, 0, 'Have you returned with proof of \'Warchief\' Kargath Bladefist\'s demise?', 0), -- Turning the Tide
(29656, 0, 0, 0, 0, 'Did you bring me the cloth?', 0), -- O'mrogg's Warcloth
(29649, 0, 0, 0, 0, 'Did you bring the ember? We don\'t have much time!', 0); -- How to Save a Life

UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=11443; -- Daggercap Divin'
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=11420; -- The Path to Payback
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=11333; -- Into the World of Spirits
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=26365 WHERE `ID`=11255; -- Prisoners of Wyrmskull
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=26365 WHERE `ID`=11244; -- Rescuing the Rescuers
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=11243; -- If Valgarde Falls...
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='<Yorik lets out a sigh of relief.>$B$BWe thought you might not show up, $n.' WHERE `ID`=12472; -- Finality
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12467; -- Chasing Icestorm: Thel'zan's Phylactery
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12143; -- Canyon Chase
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12142; -- Pest Control
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12478; -- Frostmourne Cavern
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12457; -- The Chain Gun And You
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12455; -- Scattered To The Wind
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Clear out the Onslaught Base Camp, $n.', `VerifiedBuild`=26365 WHERE `ID`=12476; -- The Return of the Crusade?
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12477; -- The Path of Redemption
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12475; -- What Secrets Men Hide
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='I have enough murkweed to make more elixirs, $n.', `VerifiedBuild`=26365 WHERE `ID`=12291; -- The Forgotten Tale
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12290; -- The Murkweed Elixir
UPDATE `quest_request_items` SET `CompletionText`='I heard about your bravery in the mine, $n.' WHERE `ID`=12281; -- Understanding the Scourge War Machine
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12441; -- Wanted: High Shaman Bloodpaw
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12282; -- Imprints on the Past
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12311; -- The Noble's Crypt
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12269; -- Not In Our Mine
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12272; -- The Bleeding Ore
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Put them out of their misery, $n.', `VerifiedBuild`=26365 WHERE `ID`=12258; -- The Fate of the Dead
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12253; -- Rescue from Town Square
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `CompletionText`='Hurry, $n! You need to save the helpless villagers!', `VerifiedBuild`=26365 WHERE `ID`=12237; -- Flight of the Wintergarde Defender
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12464; -- My Old Enemy
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12174; -- High Commander Halford Wyrmbane
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `CompletionText`='How fares the fight?  Are we pushing them back?', `VerifiedBuild`=26365 WHERE `ID`=12372; -- Defending Wyrmrest Temple
UPDATE `quest_request_items` SET `CompletionText`='It is good to finally meet you in person, $n. I have known you since before you were born.' WHERE `ID`=12123; -- Informing the Queen
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='You\'ve returned! Have you done as I\'ve asked of you?', `VerifiedBuild`=26365 WHERE `ID`=12418; -- Through Fields of Flame
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=12417; -- Return to the Earth
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=12416; -- Heated Battle
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=11960; -- Planning for the Future
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='I sense that High Cultist Zangus yet lives.$B$BIs there something wrong, $n? Perhaps you need to rest first?', `VerifiedBuild`=26365 WHERE `ID`=12169; -- The High Cultist
UPDATE `quest_request_items` SET `CompletionText`='I sense something foul is near.$B$BIt is upon your person! What is it, $n?' WHERE `ID`=12168; -- The Favor of Zangus
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='An added benefit of saving the ancients may turn out to be that they will consider assisting the Alliance with its hardships. Regardless, it is the right thing to do.$B$BNow, how many were you able to strengthen, $c?', `VerifiedBuild`=26365 WHERE `ID`=12092; -- Strengthen the Ancients
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12083; -- Atop the Woodlands
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12065; -- The Focus on the Beach
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12060; -- Projections and Plans
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=12171; -- Of Traitors and Treason
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12004; -- Prevent the Accord
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `CompletionText`='Are you attuned? You mustn\'t lie about this, $n.$B$BIf you fail to prepare yourself properly, and I teach you the spell, the first time that you cast it will be the last time anyone will ever see you!', `VerifiedBuild`=26365 WHERE `ID`=12172; -- Attunement to Dalaran
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=12000; -- Rifle the Bodies
UPDATE `quest_request_items` SET `CompletionText`='Hail, $n.', `VerifiedBuild`=26365 WHERE `ID`=12019; -- Last Rites
UPDATE `quest_request_items` SET `CompletionText`='You\'re back, $n.  Did you get the phylactery?', `VerifiedBuild`=26365 WHERE `ID`=11956; -- Finding the Phylactery
UPDATE `quest_request_items` SET `CompletionText`='Did you make any progress?  We\'re in a bind here.', `VerifiedBuild`=26365 WHERE `ID`=11944; -- Surrounded!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=11699; -- I'm Stuck in this Damned Cage... But Not For Long!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=11670; -- It Was The Orcs, Honest!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=11658; -- Plan B
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=11653; -- Hah... You're Not So Big Now!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=11723; -- Deploy the Shake-n-Quake!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=11715; -- Fueling the Project
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=11713; -- Scouting the Sinkholes
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=11796; -- Emergency Protocol: Section 8.2, Paragraph D
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=11795; -- Emergency Protocol: Section 8.2, Paragraph C
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=11728; -- Lupus Pupus
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=11726; -- A Little Bit of Spice
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=11788; -- Lefty Loosey, Righty Tighty
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=11730; -- Master and Servant
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=11729; -- The Ultrasonic Screwdriver
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=11650; -- Just a Few More Things...
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=11645; -- Dirty, Stinkin' Snobolds!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=11710; -- What's the Matter with the Transmatter?
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26365 WHERE `ID`=11712; -- Re-Cursive
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `VerifiedBuild`=26365 WHERE `ID`=11867; -- Can't Get Ear-nough...
UPDATE `quest_request_items` SET `CompletionText`='Have you rallied the survivors, $n?', `VerifiedBuild`=26365 WHERE `ID`=11965; -- Call to Arms!
UPDATE `quest_request_items` SET `CompletionText`='You spoke to William, $n?' WHERE `ID`=11600; -- The Late William Allerton
UPDATE `quest_request_items` SET `CompletionText`='You done yet, $n?', `VerifiedBuild`=26365 WHERE `ID`=12035; -- Repurposed Technology
UPDATE `quest_request_items` SET `CompletionText`='The ore, $n, is it safe?', `VerifiedBuild`=26365 WHERE `ID`=11904; -- Fruits of Our Labor
UPDATE `quest_request_items` SET `CompletionText`='Have you done what I asked of you, $n?', `VerifiedBuild`=26365 WHERE `ID`=11913; -- Take No Chances
UPDATE `quest_request_items` SET `CompletionText`='Have you accomplished the task I asked of you, $n?', `VerifiedBuild`=26365 WHERE `ID`=11794; -- The Hunt is On
UPDATE `quest_request_items` SET `CompletionText`='Did you succeed, $n?  We need to slow down the Scourge or Valiance Keep will be overrun.', `VerifiedBuild`=26365 WHERE `ID`=11897; -- Plug the Sinkholes
UPDATE `quest_request_items` SET `CompletionText`='You\'re back, $n.', `VerifiedBuild`=26365 WHERE `ID`=11792; -- Enemies of the Light
UPDATE `quest_request_items` SET `CompletionText`='You\'re back.  Good news, hopefully?', `VerifiedBuild`=26365 WHERE `ID`=11889; -- Death From Above
UPDATE `quest_request_items` SET `CompletionText`='You\'re back.  Hopefully you\'ve put a dent in the enemy\'s numbers.', `VerifiedBuild`=26365 WHERE `ID`=11797; -- The Siege
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='The cut of your clothes suggests to me that you are a Tailor yourself and could easily learn the skill that I have to teach.$B$BMany of the northern humanoids wear clothes that can quickly be converted into cloth if you know the knack of doing it.$B$BFor a small fee I can teach you the art of Cloth Scavenging that will give you additional cloth from the humanoids of Northrend.' WHERE `ID`=13265; -- Cloth Scavenging
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=11544; -- Ata'mal Armaments
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=11541; -- Disrupt the Greengill Coast
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26365 WHERE `ID`=29614; -- Containment is Key
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=10664; -- Additional Materials
UPDATE `quest_request_items` SET `CompletionText`='Yes, $n?', `VerifiedBuild`=26365 WHERE `ID`=10959; -- The Fall of the Betrayer
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0 WHERE `ID`=11006; -- More Shadow Dust
UPDATE `quest_request_items` SET `CompletionText`='Many refugees still need treatment for their poisonous wounds.  Have you brought more venom sacs for me to use, $n?' WHERE `ID`=10019; -- More Venom Sacs
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you obtained the venom sacs, $n?  These refugees can\'t wait much longer.' WHERE `ID`=10017; -- Strained Supplies
UPDATE `quest_request_items` SET `CompletionText`='Do you bring the feathers I asked for, $n?' WHERE `ID`=10917; -- The Outcast's Plight
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you obtained any more arcane tomes, $n?' WHERE `ID`=10419; -- Arcane Tomes
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you obtained an arcane tome yet, $n?' WHERE `ID`=10416; -- Synthesis of Power
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='What have you done for us lately, $n?  The war against Kael\'thas is not going to fight itself, you know?', `VerifiedBuild`=26365 WHERE `ID`=10658; -- More Sunfury Signets
UPDATE `quest_request_items` SET `CompletionText`='Go on, $n.  Speak.' WHERE `ID`=10412; -- Firewing Signets
UPDATE `quest_request_items` SET `CompletionText`='Yes, $n?', `VerifiedBuild`=26365 WHERE `ID`=10957; -- Redemption of the Ashtongue

UPDATE `quest_request_items` SET `VerifiedBuild`=26365 WHERE `ID` IN (12167, 12166, 11942, 11938, 11718, 11908, 11903, 11789, 11536, 11540, 11543, 11547, 11533, 11537, 11546, 11525, 11523);

DELETE FROM `quest_request_items` WHERE `ID` IN (11414 /*Brother Betrayers*/, 11489 /*Iron Rune Constructs and You: Collecting Data*/, 11477 /*Out of My Element?*/, 11430 /*Harpoon Master Yavus*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(11414, 0, 0, 0, 0, '<A low growl rises from Ulfang\'s throat.>$B$BBjomolf and Varg are not dead!', 26654), -- Brother Betrayers
(11489, 0, 6, 0, 0, 'Fits like a glove, don\'t it?', 26654), -- Iron Rune Constructs and You: Collecting Data
(11477, 0, 1, 0, 0, 'You\'ll need to kill until you\'ve had your fill.', 26654), -- Out of My Element?
(11430, 0, 6, 0, 0, 'Have you taken care of Yavus?', 26654); -- Harpoon Master Yavus

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26654 WHERE `ID`=11202; -- Mission: Eternal Flame
UPDATE `quest_request_items` SET `CompletionText`='$n, you have returned. What news of Ulfang?' WHERE `ID`=11326; -- Alpha Worg
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26654 WHERE `ID`=11396; -- Bring Down Those Shields
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=11395; -- It's a Scourge Device
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26654 WHERE `ID`=11394; -- And You Thought Murlocs Smelled Bad!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26654 WHERE `ID`=11154; -- Scare the Guano Out of Them!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26654 WHERE `ID`=11322; -- The Cleansing
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26654 WHERE `ID`=11224; -- Send Them Packing
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='It is unfortunate that the captain had to have you go rile up the proto-drakes. Though they seem to lack the intelligence of the dragons that we know, they still seem to be noble creatures. Not to mention the situation it places us in.$B$BDare I ask if you have dealt with the situation?', `VerifiedBuild`=26654 WHERE `ID`=11188; -- Two Wrongs...
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26654 WHERE `ID`=11190; -- One Size Does Not Fit All
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26654 WHERE `ID`=11157; -- The Clutches of Evil
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `CompletionText`='We\'re talking again are we?  That must mean that you\'ve done it!  You\'ve shown those rotten Northsea pirates a thing or two!$B$BRight?', `VerifiedBuild`=26654 WHERE `ID`=11153; -- Break the Blockade
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26654 WHERE `ID`=11155; -- Shoveltusk Soup Again?
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26654 WHERE `ID`=11495; -- The Delicate Sound of Thunder
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26654 WHERE `ID`=11494; -- Lightning Infused Relics
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26654 WHERE `ID`=11491; -- Iron Rune Constructs and You: The Bluff
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=26654 WHERE `ID`=11485; -- Iron Rune Constructs and You: Rocket Jumping
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=26654 WHERE `ID`=11484; -- We Have the Technology
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26654 WHERE `ID`=11483; -- We Can Rebuild It
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `CompletionText`='You are in control now, $n. Guide your falcon and bring me those eggs.', `VerifiedBuild`=26654 WHERE `ID`=11470; -- There Exists No Honor Among Birds
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26654 WHERE `ID`=11468; -- Falcon Versus Hawk
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26654 WHERE `ID`=11465; -- The Ransacked Caravan
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='This is an important exercise, $n. If you are to become a falconer you must learn how to feed your bird.\n', `VerifiedBuild`=26654 WHERE `ID`=11460; -- Trust is Earned
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26654 WHERE `ID`=11475; -- Tools to Get the Job Done
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `VerifiedBuild`=26654 WHERE `ID`=11421; -- It Goes to 11...
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26654 WHERE `ID`=11429; -- Drop It then Rock It!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26654 WHERE `ID`=11344; -- Anguish of Nifflevar
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11333; -- Into the World of Spirits
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=11289; -- Guided by Honor
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26654 WHERE `ID`=11426; -- Locating the Mechanism
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11420; -- The Path to Payback
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26654 WHERE `ID`=11290; -- Dragonflayer Battle Plans
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=11278; -- Return to Valgarde
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11300; -- Stunning Defeat at the Ring
UPDATE `quest_request_items` SET `EmoteOnComplete`=4, `EmoteOnIncomplete`=4, `VerifiedBuild`=26654 WHERE `ID`=11277; -- The Depths of Depravity

UPDATE `quest_request_items` SET `VerifiedBuild`=26654 WHERE `ID` IN (11416, 11343, 11288);

DELETE FROM `quest_request_items` WHERE `ID` IN (12807 /*The Story Thus Far...*/, 13046 /*Feeding Arngrim*/, 12879 /*Fury of the Frostborn King*/, 12864 /*Missing Scouts*/, 24587 /*Ignis the Furnace Master Must Die!*/, 12138 /*... Or Maybe We Don't*/, 11284 /*The Yeti Next Door*/, 11235 /*Dealing With Gjalerbron*/, 11330 /*Absholutely... Thish Will Work!*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(12807, 0, 397, 0, 0, 'I suppose you think that you\'re ready to continue? How could you be though... you haven\'t yet heard the entirety of my tale!', 26822), -- The Story Thus Far...
(13046, 0, 0, 0, 0, '', 26822), -- Feeding Arngrim
(12879, 1, 0, 0, 0, 'Someone is using the Forge of Wills to create this army... Ulduar is no longer safe. $R, did you recover the core?', 0), -- Fury of the Frostborn King
(12864, 0, 0, 0, 0, 'Any sign of\'m?', 26822), -- Missing Scouts
(24587, 0, 1, 0, 0, 'Ignis is not yet dead. The fire giant must fall!', 26822), -- Ignis the Furnace Master Must Die!
(12138, 0, 1, 0, 0, 'How\'s the charging going?', 26822), -- ... Or Maybe We Don't
(11284, 0, 1, 0, 0, 'Have you had any luck removing that stupid yeti from my mine?', 26822), -- The Yeti Next Door
(11235, 0, 1, 0, 0, 'I want those filthy creatures dead! They threaten us all over the fjord, and it\'s high time we put a stop to them by wiping them out at Ssssshhhhhalerbron.$B$B<The captain says the name of the vrykul fortress derisively.>', 26822), -- Dealing With Gjalerbron
(11330, 0, 6, 0, 0, 'Well? How\'d it go ...hic?', 26822); -- Absholutely... Thish Will Work!

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12810; -- Blood in the Water
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=34, `CompletionText`='What? Vile not see lots of fire!!!$B$B$n go back and make more fire!', `VerifiedBuild`=26822 WHERE `ID`=13071; -- Vile Like Fire!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='I sense that you haven\'t yet defeated Thane Illskar. Does something stay your hand?', `VerifiedBuild`=26822 WHERE `ID`=13059; -- Revenge for the Vargul
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13093; -- Reading the Bones
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25, `VerifiedBuild`=26822 WHERE `ID`=13084; -- Vandalizing Jotunheim
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26822 WHERE `ID`=12982; -- Ebon Blade Prisoners
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=35, `VerifiedBuild`=26822 WHERE `ID`=12992; -- Crush Dem Vrykuls!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=274, `CompletionText`='Oh now, $n, I don\'t think you\'re quite done yet.', `VerifiedBuild`=26822 WHERE `ID`=12995; -- Leave Our Mark
UPDATE `quest_request_items` SET `CompletionText`='Strong gusts of wind swirl around the horn, causing its sound to echo throughout the surrounding mountains.$b$bTo any unknowing passersby, it might seem to be blowing itself....', `VerifiedBuild`=26822 WHERE `ID`=12977; -- Blowing Hodir's Horn
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='Hey there, $G lad:lass;! Good to meet ya in person. Did you find it?' WHERE `ID`=12880; -- The Master Explorer
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='Hello, $r.$B$BI am pleased that you have opted to utilize your tongue over your blade when making my acquaintance. I have found that a more and more rare quality among your kind of late.' WHERE `ID`=12877; -- The Lonesome Watcher
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26822 WHERE `ID`=12876; -- Unwelcome Guests
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12874; -- Fervor of the Frostborn
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=12871; -- Aid from the Explorers' League
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=12872; -- Norgannon's Shell
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13415; -- The Library Console
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12860; -- Data Mining
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12858; -- Pieces to the Puzzle
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12867; -- Baby Stealers
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='It\'s too cold here for the usual pests... we get harpies. Lucky us.', `VerifiedBuild`=26822 WHERE `ID`=12868; -- Sirana Iceshriek
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12866; -- Stemming the Aggressors
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=12863; -- Offering Thanks
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12854; -- On Brann's Trail
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=12794; -- The Magical Kingdom of Dalaran
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=26822 WHERE `ID`=13556; -- Eggs for Dubra'Jin
UPDATE `quest_request_items` SET `CompletionText`='If you do not put an end to my suffering soon, $n, all may be lost.', `VerifiedBuild`=26822 WHERE `ID`=12647; -- An End to the Suffering
UPDATE `quest_request_items` SET `CompletionText`='You\'ve returned.  Did you succeed?', `VerifiedBuild`=26822 WHERE `ID`=12249; -- Ursoc, the Bear God
UPDATE `quest_request_items` SET `CompletionText`='Have you brought me the ashes, $n?', `VerifiedBuild`=26822 WHERE `ID`=12248; -- Vordrassil's Sapling
UPDATE `quest_request_items` SET `CompletionText`='Do you have the seeds, $n?', `VerifiedBuild`=26822 WHERE `ID`=12250; -- Vordrassil's Seeds
UPDATE `quest_request_items` SET `CompletionText`='Have you obtained the blood samples, $n?', `VerifiedBuild`=26822 WHERE `ID`=12246; -- A Possible Link
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Have you done what I asked of you, $n?', `VerifiedBuild`=26822 WHERE `ID`=12220; -- A Dark Influence
UPDATE `quest_request_items` SET `CompletionText`='Have you gathered the samples, $n?', `VerifiedBuild`=26822 WHERE `ID`=12219; -- The Failed World Tree
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12154; -- Blackout
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12153; -- The Iron Thane and His Anvil
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12185; -- Put on Your Best Face for Loken
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12184; -- Cultivating an Image
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12131; -- We Have the Power
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12183; -- Looking the Part
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12130; -- Why Fabricate When You Can Appropriate?
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12129; -- The Perfect Plan
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12180; -- The Captive Prospectors
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12003; -- Uncovering the Tunnels
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12002; -- Brothers in Battle
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11993; -- The Runic Prophecies
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11988; -- The Runic Keystone
UPDATE `quest_request_items` SET `CompletionText`='Have you put my friends to rest yet, $n?', `VerifiedBuild`=26822 WHERE `ID`=12159; -- Souls at Unrest
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11998; -- Softening the Blow
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12414; -- Mounting Up
UPDATE `quest_request_items` SET `CompletionText`='Is it done, $n?', `VerifiedBuild`=26822 WHERE `ID`=12310; -- A Swift Response
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12255; -- The Thane of Voldrune
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=12222; -- Secrets of the Flamebinders
UPDATE `quest_request_items` SET `CompletionText`='You got some of that element 115, $n?' WHERE `ID`=12443; -- Seeking Solvent
UPDATE `quest_request_items` SET `CompletionText`='You bring me that box, $n?', `VerifiedBuild`=26822 WHERE `ID`=12292; -- Local Support
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11348; -- The Rune of Command
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11359; -- Demolishing Megalith
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11349; -- Mastering the Runes
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11358; -- The Lodestone
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11418; -- We Call Him Steelfeather
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11355; -- March of the Giants
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11346; -- The Book of Runes
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='I\'m itching to try out the new bait.$B$BHave you had any luck with Frostfin?', `VerifiedBuild`=26822 WHERE `ID`=11410; -- The One That Got Away
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11292; -- Preying Upon the Weak
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11269; -- Down to the Wire
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11329; -- I'll Try Anything!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='$n, I find it implausible that you have dealt with enough of the dormant vrykul. Come back when you have done so.', `VerifiedBuild`=26822 WHERE `ID`=11432; -- Sleeping Giants
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11236; -- Necro Overlord Mezhen
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26822 WHERE `ID`=11238; -- The Frost Wyrm and its Master
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11231; -- Of Keys and Cages
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26822 WHERE `ID`=11247; -- Burn Skorn, Burn!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11246; -- Gruesome, But Necessary
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11245; -- Towers of Certain Doom
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26822 WHERE `ID`=11332; -- Mission: Plague This!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26822 WHERE `ID`=11327; -- Mission: Package Retrieval

UPDATE `quest_request_items` SET `VerifiedBuild`=26822 WHERE `ID` IN (12949, 12986, 12865, 12870, 12247, 12307, 12299, 12223, 12227, 12226, 12217, 12216, 12215, 12212, 11239, 11504);

DELETE FROM `quest_request_items` WHERE `ID`=13338;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(13338, 0, 1, 0, 0, 'Have you crippled Corp\'rethar\'s defenders?', 26899); -- The Guardians of Corp'rethar

UPDATE `quest_request_items` SET `CompletionText`='Light be with you, $n.', `VerifiedBuild`=26899 WHERE `ID`=13403; -- Tirion's Gambit
UPDATE `quest_request_items` SET `CompletionText`='Did you see, $n?  Did you?', `VerifiedBuild`=26899 WHERE `ID`=13400; -- The Hunter and the Prince
UPDATE `quest_request_items` SET `CompletionText`='$n, you\'re back!', `VerifiedBuild`=26899 WHERE `ID`=13397; -- Sindragosa's Fall
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26899 WHERE `ID`=13339; -- Shatter the Shards
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26899 WHERE `ID`=13335; -- Before the Gate of Horror
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=26899 WHERE `ID`=13314; -- Get the Message
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Have you killed the banner-bearers and stopped their attempt to use the fallen against us?', `VerifiedBuild`=26899 WHERE `ID`=13334; -- Bloodspattered Banners
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26899 WHERE `ID`=13337; -- The Ironwall Rampart
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26899 WHERE `ID`=13332; -- Raise the Barricades
UPDATE `quest_request_items` SET `CompletionText`='Well, $c?$b$bWe have a few less cultists to worry about?', `VerifiedBuild`=26899 WHERE `ID`=13321; -- Retest Now
UPDATE `quest_request_items` SET `CompletionText`='Greetings, $c.$b$bCan I report that we\'ve rendered another plague cauldron useless?', `VerifiedBuild`=26899 WHERE `ID`=13297; -- Neutralizing the Plague
UPDATE `quest_request_items` SET `CompletionText`='Well, $r?$b$bDid your abomination friends prove effective?', `VerifiedBuild`=26899 WHERE `ID`=13288; -- That's Abominable!
UPDATE `quest_request_items` SET `CompletionText`='You\'ve returned, $c...$b$bAnything to report?', `VerifiedBuild`=26899 WHERE `ID`=13287; -- Poke and Prod
UPDATE `quest_request_items` SET `CompletionText`='Well, $n?$b$bWhat have you learned?', `VerifiedBuild`=26899 WHERE `ID`=13231; -- The Broken Front

UPDATE `quest_request_items` SET `VerifiedBuild`=26899 WHERE `ID` IN (13398, 13391, 13387, 13346, 13345, 13342, 13320, 13319, 13318, 13315, 13298, 13295, 13294, 13291);

DELETE FROM `quest_request_items` WHERE `ID` IN (29141 /*The Harder They Fall*/, 25499 /*Agility Training: Run Like Hell!*/, 29200 /*Leyara*/, 29149 /*Rage Against the Flames*/, 29195 /*A Ritual of Flame*/, 25352 /*Sweeping the Shelf*/, 25278 /*Cleaning House*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29141, 0, 0, 0, 0, 'Even with such monstrous opponents marching upon them, not a single one of my men has quit the field. Jarod is to be commended. He inspires the men like no other.', 26972), -- The Harder They Fall
(25499, 0, 0, 0, 0, 'Yes?', 26972), -- Agility Training: Run Like Hell!
(29200, 0, 0, 0, 0, 'Hamuul really shouldn\'t worry about the affairs of a lone druid. The hour of our attack is at hand!', 26972), -- Leyara
(29149, 0, 0, 0, 0, 'There isn\'t time to waste, $r.', 26972), -- Rage Against the Flames
(29195, 0, 0, 0, 0, 'Continue the fight, $n. Only a short while longer now.', 26972), -- A Ritual of Flame
(25352, 0, 6, 0, 0, 'The battle heats up! How goes it?', 26972), -- Sweeping the Shelf
(25278, 0, 1, 0, 0, 'Gar\'gol isn\'t exactly the brightest torch on the mountain, if you know what I mean.', 26972); -- Cleaning House

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=26972 WHERE `ID`=29139; -- Aggressive Growth
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26972 WHERE `ID`=29138; -- Burn Victims
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=26972 WHERE `ID`=29179; -- Hostile Elements

UPDATE `quest_request_items` SET `VerifiedBuild`=26972 WHERE `ID` IN (27176, 29147, 29199, 25271);

DELETE FROM `quest_request_items` WHERE `ID` IN (25564 /*Stormwind Elite Aquatic and Land Forces*/, 25545 /*To Arms!*/, 25546 /*Traveling on Our Stomachs*/, 25357 /*Buy Us Some Time*/, 25281 /*Pay It Forward*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(25564, 0, 0, 0, 0, 'Were you able to secure that equipment, $c?', 27101), -- Stormwind Elite Aquatic and Land Forces
(25545, 0, 0, 0, 0, 'Have you recovered our gear, $r?', 27101), -- To Arms!
(25546, 0, 0, 0, 0, 'Were you able to find anything for my men and I to eat, $c?', 27101), -- Traveling on Our Stomachs
(25357, 0, 0, 0, 0, 'Have you given the naga something to think about, $c?', 27101), -- Buy Us Some Time
(25281, 0, 0, 0, 0, 'Were you able to rescue the soldiers, $r?$b$bWe will perish without their help...', 27101); -- Pay It Forward

UPDATE `quest_request_items` SET `VerifiedBuild`=27101 WHERE `ID`=24432; -- Sea Legs

DELETE FROM `quest_request_items` WHERE `ID` IN (25888 /*Decompression*/, 25885 /*What? What? In My Gut...?*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(25888, 0, 0, 0, 0, 'Were you able to rescue some of the imprisoned soldiers, $n?', 27178), -- Decompression
(25885, 0, 0, 0, 0, 'Were you able to find me any of their seaweed, $c?', 27178); -- What? What? In My Gut...?

UPDATE `quest_request_items` SET `VerifiedBuild`=27178 WHERE `ID`=27699; -- Shark Weak

DELETE FROM `quest_request_items` WHERE `ID` IN (28497 /*Fire From the Sky*/, 28351 /*Unlimited Potential*/, 26132 /*Fiends from the Netherworld*/, 26070 /*Clearing the Defiled*/, 25975 /*Treasure Reclamation*/, 25977 /*A Standard Day for Azrajar*/, 25950 /*Sira'kess Slaying*/, 25981 /*Those Aren't Masks*/, 26080 /*One Last Favor*/, 26019 /*Enormous Eel Egg*/, 26017 /*A Lure*/, 26018 /*Coldlights Out*/, 26015 /*Phosphora Hunting*/, 26106 /*Fuel-ology 101*/, 26103 /*Bio-Fuel*/, 25860 /*At All Costs*/, 25626 /*Visions of the Past: Rise from the Deep*/, 25894 /*Hostile Waters*/, 25897 /*Unfurling Plan*/, 25895 /*Come Prepared*/, 25755 /*Visions of the Past: The Slaughter of Biel'aran Ridge*/, 25754 /*Gauging Success*/, 25753 /*Fallen But Not Forgotten*/, 25752 /*Swift Action*/, 25751 /*Properly Inspired*/, 25749 /*Not Entirely Unprepared*/, 25748 /*Clear Goals*/, 25760 /*Visions of the Past: The Invasion of Vashj'ir*/, 27716 /*Piece of the Past*/, 25583 /*Upon the Scene of Battle*/, 25579 /*Caught Off-Guard*/, 25582 /*A Better Vantage*/, 25580 /*Swift Approach*/, 25581 /*An Occupation of Time*/, 25540 /*Bellies Await*/, 25538 /*Odor Coater*/, 25537 /*Art of Attraction*/, 25539 /*Clamming Up*/, 25536 /*Cold Welcome*/, 25920 /*Still Valuable*/, 25918 /*Hopelessly Gearless*/, 25919 /*Body Blows*/, 25916 /*Breaking Through*/, 25909 /*Capture the Crab*/, 27687 /*An Opened Can of Whoop Gnash*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(28497, 0, 0, 0, 0, 'Don\'t think twice, $n.$b$bThese guys are rotten to the core.', 27219), -- Fire From the Sky
(28351, 0, 0, 0, 0, 'Did you capture the Pygmies I need, friend?', 27219), -- Unlimited Potential
(26132, 0, 1, 0, 0, 'There are still more fiends to be destroyed.', 27219), -- Fiends from the Netherworld
(26070, 0, 25, 0, 0, 'I\'m going to need you to kill a few more of those things. The shamans here are very particular about it. You\'d think they were druids.', 27219), -- Clearing the Defiled
(25975, 6, 6, 0, 0, 'How much plunder have you managed to reclaim, $n?', 27219), -- Treasure Reclamation
(25977, 0, 6, 0, 0, 'It\'s done then?', 27219), -- A Standard Day for Azrajar
(25950, 0, 1, 0, 0, 'This one\'s not bright and breezy, love, but when they\'re brown bread, we\'ll have ourselves a good tumble down the sink, you and I.$B$BRight?', 27219), -- Sira'kess Slaying
(25981, 6, 6, 0, 0, 'How many you got?', 27219), -- Those Aren't Masks
(26080, 0, 0, 0, 0, 'Have you found Oskar and Humphrey?', 0), -- One Last Favor
(26019, 0, 0, 0, 0, 'What\'ve ya got there, $n?', 0), -- Enormous Eel Egg
(26017, 0, 0, 0, 0, 'How many did ya catch?', 27219), -- A Lure
(26018, 0, 0, 0, 0, 'Ya gotta get back out there, $n.  Cap\'n needs this recon, and he\'s counting on me!', 27219), -- Coldlights Out
(26015, 0, 0, 0, 0, 'We need enough phosphora to make a really bright light, especially if you\'re going to be competing with those murlocs.', 27219), -- Phosphora Hunting
(26106, 0, 0, 0, 0, 'We haven\'t found the right combination yet, $n.  Keep at it!  I\'m sure you can figure it out!', 27219), -- Fuel-ology 101
(26103, 0, 0, 0, 0, 'How did the device work, $n?', 27219), -- Bio-Fuel
(25860, 0, 0, 0, 0, 'I am trusting you to safeguard us, Battlemaiden.', 27219), -- At All Costs
(25626, 0, 1, 0, 0, 'The ruins are surely still swarming with naga. Pay close attention to their patrols and I\'m sure you\'ll be able to slip through.', 27219), -- Visions of the Past: Rise from the Deep
(25894, 0, 1, 0, 0, 'These scroungers seem intensely curious about our equipment. Sometimes suicidally so. I wonder what attracts them to it so much.', 27219), -- Hostile Waters
(25897, 0, 0, 0, 0, 'The rope ties the whole plan together!', 27219), -- Unfurling Plan
(25895, 0, 0, 0, 0, 'A whole big box of amazing! That\'s what it is. I need more amazing in my life.$B$BDon\'t worry, I\'ll share.', 27219), -- Come Prepared
(25755, 0, 1, 0, 0, 'I know it\'s a hard request to head - a whim in a time of dire consequences. You just have to trust me. More than anything right know, we need to know why the naga are here and what they are capable of.', 27219), -- Visions of the Past: The Slaughter of Biel'aran Ridge
(25754, 0, 6, 0, 0, 'Any word... on their numbers?', 27219), -- Gauging Success
(25753, 0, 1, 0, 0, 'These guys aren\'t in good shape. We may need to retreat sooner than we\'d like.', 27219), -- Fallen But Not Forgotten
(25752, 0, 1, 0, 0, 'Speak to Enginner Hexascrub to secure a mount for the assault.', 27219), -- Swift Action
(25751, 5, 5, 0, 0, 'Tick, tock, tick, tock. Always in such a hurry. No time for innovation. What I wouldn\'t give for a lab again!', 27219), -- Properly Inspired
(25749, 0, 0, 0, 0, 'Finished already?', 27219), -- Not Entirely Unprepared
(25748, 0, 0, 0, 0, 'They\'re amassing infantry to the south.$B$BWe need more time. Do anything you can to clear them out.', 27219), -- Clear Goals
(25760, 0, 6, 0, 0, 'That took longer than expected. Did you learn anything useful? Who did the blade belong to?', 27219), -- Visions of the Past: The Invasion of Vashj'ir
(27716, 1, 0, 0, 0, 'Hah! Did you see the admiral giving me dirty looks and decide to throw some sympathy my way? I\'ve pretty much lost hope of making him understand that these ruins offer us some opportunity to salvage some usefulness out of this whole mess.$B$BI\'d actually hoped that you might turn up again - you seem like the only one I can rely on. Wait... what\'s that you have there?', 0), -- Piece of the Past
(25583, 6, 0, 0, 0, 'Yes, $c?', 0), -- Upon the Scene of Battle
(25579, 0, 1, 0, 0, 'This is a matter of life and death, $c. The longer we wait, the more we risk giving away our position.', 27219), -- Caught Off-Guard
(25582, 0, 0, 0, 0, 'We are not hard to find in this cave. We will need to strike quickly - before the naga start searching for us.', 27219), -- A Better Vantage
(25580, 0, 1, 0, 0, 'It seems clear that they do not take us seriously, which actually worries me. We have no idea how many of these naga there really are. As time passes, I grow to fear that the shell we escaped was only a small piece of a very large puzzle.', 27219), -- Swift Approach
(25581, 0, 1, 0, 0, 'Let\'s keep the Admiral out of this, shall we? That man has only vengeance on his mind, and his eyes are locked forward. The past is meaningless to him.', 27219), -- An Occupation of Time
(25540, 1, 0, 0, 0, 'You look to have come back to us with purpose. Was your trip successful?', 0), -- Bellies Await
(25538, 0, 0, 0, 0, 'Fishy companions for all!', 27219), -- Odor Coater
(25537, 0, 5, 0, 0, 'These chemicals are of utmost importance to my defensive diving strategies. Delay not, for we all all in murloc-laced peril!', 27219), -- Art of Attraction
(25539, 6, 6, 0, 0, 'Has your clam-laden frolic proved fruitful?', 27219), -- Clamming Up
(25536, 0, 0, 0, 0, 'Let me know if you get things taken care of down there. We\'re stretched pretty thin and I\'m getting worried about the safety of the divers.', 27219), -- Cold Welcome
(25920, 0, 0, 0, 0, 'The naga must have some ulterior motive with these pearls.  If I had time to study them, I\'m certain I could figure it out.', 27219), -- Still Valuable
(25918, 0, 0, 0, 0, 'In my youth, I was given some training on spearfighting.$b$b\"Stick them with the pointy end,\" I think it was.', 27219), -- Hopelessly Gearless
(25919, 0, 0, 0, 0, 'You\'d better keep trying, $n.  These naga aren\'t going anywhere unless you wake the creature up.', 27219), -- Body Blows
(25916, 0, 0, 0, 0, 'The ritual is not yet complete, $n.', 27219), -- Breaking Through
(25909, 0, 0, 0, 0, 'I hope this works.  My skills as a shaman are limited, and I fear that this task may be too much for us.', 27219), -- Capture the Crab
(27687, 0, 0, 0, 0, 'You took down that Sea Giant, $c?', 0); -- An Opened Can of Whoop Gnash

DELETE FROM `quest_request_items` WHERE `ID` IN (27042 /*Fight Fire and Water and Air with...*/, 27006 /*Fly Over*/, 29328 /*Elemental Bonds: Desire*/, 29327 /*Elemental Bonds: Doubt*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(27042, 0, 5, 0, 0, 'Yer gonna have ta do better than that, $g laddie : missy;!$B$BNow get back up there an\' finish the job or do I have ta go an\' do it myself?', 27291), -- Fight Fire and Water and Air with...
(27006, 0, 6, 0, 0, 'What\'d ya see? What are those cheese lovers up ta?', 27291), -- Fly Over
(29328, 0, 0, 0, 0, 'My Go\'el cannot tread these waters forever, $n!', 27291), -- Elemental Bonds: Desire
(29327, 0, 0, 0, 0, 'Stay vigilant, $n! Do not give up on Go\'el.', 27291); -- Elemental Bonds: Doubt

UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=27291 WHERE `ID`=27004; -- The Twilight Plot

DELETE FROM `quest_request_items` WHERE `ID` IN (29670 /*Maul Gormal*/, 29587 /*Unbound*/, 29580 /*Orchard-Supplied Hardware*/, 29585 /*Spitfire*/, 31319 /*Emergency Response*/, 30502 /*Jaded Heart*/, 30500 /*Residual Fallout*/, 30568 /*Helping the Cause*/, 30565 /*An Unexpected Advantage*/, 30005 /*Lighting Up the Sky*/, 29999 /*The Rider's Bind*/, 30001 /*Moth-Ridden*/, 30002 /*Pages of History*/, 29997 /*The Scryer's Dilemma*/, 30495 /*Love's Labor*/, 30140 /*The Rider's Journey*/, 30137 /*Egg Collection*/, 30136 /*Empty Nests*/, 30135 /*Beating the Odds*/, 29624 /*Attention*/, 29637 /*The Rumpus*/, 29631 /*Burning Bright*/, 29630 /*And a Heavy Fist*/, 29629 /*A Steady Hand*/, 29628 /*A Strong Back*/, 29627 /*A Proper Weapon*/, 29635 /*Xiao, the Eater*/, 29634 /*Husshun, the Wizened*/, 29633 /*Zhi-Zhi, the Dextrous*/, 29632 /*Becoming Battle-Ready*/, 29620 /*The Great Banquet*/, 29619 /*A Courteous Guest*/, 29756 /*A Humble Offering*/, 29753 /*Back to Nature*/, 29752 /*The Wayward Dead*/, 29750 /*Vessels of the Spirit*/, 29751 /*Ritual Artifacts*/, 29749 /*An Urgent Plea*/, 29926 /*Calamity Jade*/, 29928 /*I Have No Jade And I Must Scream*/, 29925 /*All We Can Spare*/, 31613 /*Volatile Greenstone Brew*/, 29920 /*Getting Permission*/, 29881 /*The Perfect Color*/, 29882 /*Quill of Stingers*/, 29717 /*Down Kitty!*/, 29866 /*The Threads that Stick*/, 29865 /*The Silkwood Road*/, 29716 /*The Double Hozen Dare*/, 31230 /*Welcome to Dawn's Blossom*/, 29900 /*An Ancient Legend*/, 29899 /*Rest in Peace*/, 29898 /*Sacred Waters*/, 29893 /*Hue*/, 29892 /*Body*/, 29891 /*Potency*/, 31130 /*A Visit with Lorewalker Cho*/, 29904 /*Bigger Fish to Fry*/, 29903 /*A Perfect Match*/, 29887 /*The Elder's Instruments*/, 29762 /*Family Heirlooms*/, 29885 /*Road Rations*/, 29883 /*The Pearlfin Situation*/, 29759 /*Kung Din*/, 29560 /*Ancient Power*/, 29559 /*Freeing Our Brothers*/, 29558 /*The Path of War*/, 29555 /*The White Pawn*/, 31744 /*Unfair Trade*/, 31741 /*Twinspire Keep*/, 31743 /*Smoke Before Fire*/, 31742 /*Fractured Forces*/, 31738 /*Pillaging Peons*/, 29552 /*Critical Condition*/, 31735 /*The Right Tool For The Job*/, 31732 /*Unleash Hell*/, 29548 /*The Mission*/, 27702 /*Coup de Grace*/, 27700 /*Dragon, Unchained*/, 27695 /*The Elementium Axe*/, 27688 /*Distract Them for Me*/, 27654 /*Bring the Hammer Down*/, 27652 /*Dark Assassins*/, 27500 /*Four Heads are Better than None*/, 27490 /*SI:7 Drop*/, 27496 /*Call in the Artillery*/, 27492 /*Ogres & Ettins*/, 28103 /*Easy Pickings*/, 28104 /*Precious Goods*/, 28655 /*Wild, Wild, Wildhammer Wedding*/, 28411 /*Something Stewed*/, 28410 /*Something Stolen*/, 28409 /*Something Brewed*/, 28408 /*Something Bold*/, 28413 /*Words and Music By...*/, 28379 /*Ogre Bashin'*/, 28378 /*Find Fanny*/, 28244 /*Eye Spy*/, 28243 /*The Eyes Have It*/, 28280 /*Tear Them From the Sky!*/, 28242 /*We All Must Sacrifice*/, 28215 /*Potential Energy*/, 28212 /*Hot Stuff*/, 28211 /*Tempered in Elemental Flame*/, 28216 /*Magmalord Falthazar*/, 27752 /*Fight Like a Wildhammer*/, 27753 /*Never Leave a Dinner Behind*/, 27754 /*Dragonmaw Takedown*/, 27651 /*Doing It Like a Dunwald*/, 27649 /*A Steady Supply*/, 27647 /*Anything But Water*/, 27646 /*Finding Beak*/, 27648 /*Once More Into The Fire*/, 27641 /*While Meeting The Family*/, 27642 /*Sifting Through The Wreckage*/, 27817 /*Dropping the Hammer*/, 27811 /*The Scent of Battle*/, 27810 /*The Fighting Spirit*/, 27815 /*Somethin' for the Boys*/, 27813 /*Death Worthy of a Dragonmaw*/, 27805 /*Small Comforts*/, 27804 /*The Only Homes We Have*/, 27803 /*Welcome Relief*/, 27537 /*Any Portal in a Storm*/, 27515 /*Roots'll Do 'Er*/, 27468 /*Siege Tank Rescue*/, 27433 /*Shredderectomy*/, 27366 /*Landgrab*/, 27341 /*Scouting the Shore*/, 27178 /*Naga Reinforcements*/, 28596 /*Welcome to Highbank!*/, 29329 /*Elemental Bonds: Patience*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29670, 0, 0, 0, 0, 'We are ready to fight the mogu leader whenever you are.', 27326), -- Maul Gormal
(29587, 0, 0, 0, 0, 'Those ropes should give with a strong tug.', 27326), -- Unbound
(29580, 0, 0, 0, 0, 'Were there any tools left?', 27326), -- Orchard-Supplied Hardware
(29585, 0, 0, 0, 0, 'Best not to judge our prized cider by its flavor in this state.', 27326), -- Spitfire
(31319, 0, 0, 0, 0, 'My thoughts will be with your companions, $n.$b$bMay they be made whole again soon.', 27326), -- Emergency Response
(30502, 0, 0, 0, 0, 'Do you have the jade, $n?', 27326), -- Jaded Heart
(30500, 0, 0, 0, 0, 'This, it seems, is only the tip of the iceberg, $n.', 27326), -- Residual Fallout
(30568, 0, 0, 0, 0, 'Is everyone in order and ready to move?', 27326), -- Helping the Cause
(30565, 0, 0, 0, 0, 'Did ye find my missing gears and bolts?', 27326), -- An Unexpected Advantage
(30005, 0, 0, 0, 0, 'I love to see fireworks lighting up the sky!', 27326), -- Lighting Up the Sky
(29999, 0, 0, 0, 0, 'I hope they didn\'t give you too much trouble.', 27326), -- The Rider's Bind
(30001, 0, 0, 0, 0, 'I can see the moths eating the pages from here!', 27326), -- Moth-Ridden
(30002, 0, 0, 0, 0, 'My stomach is too fragile to handle the squashing of bugs. Is it done?', 27326), -- Pages of History
(29997, 0, 0, 0, 0, 'The pools are clouded. I will need my staff to calm the spirits and speak to the water.', 27326), -- The Scryer's Dilemma
(30495, 0, 0, 0, 0, 'Did you deliver the jade in time?', 27326), -- Love's Labor
(30140, 0, 0, 0, 0, 'The wild cloud serpents live in a delicate balance with nature. Their rare eggs are quite vulnerable to enemies.', 0), -- The Rider's Journey
(30137, 0, 0, 0, 0, 'The saurok keep the stolen serpent eggs in their camp.', 27326), -- Egg Collection
(30136, 0, 0, 0, 0, 'Did you return the hatchlings to their nests?', 27326), -- Empty Nests
(30135, 0, 0, 0, 0, 'The Order rarely meddles with the natural balance on this island, but it is too important to save the serpents.', 27326), -- Beating the Odds
(29624, 0, 0, 0, 0, 'What are you waiting for?', 27326), -- Attention
(29637, 0, 0, 0, 0, 'Good luck, $n.', 27326), -- The Rumpus
(29631, 0, 0, 0, 0, 'Please, do not speak of our arrangement with others. My cowardice shames me.', 27326), -- Burning Bright
(29630, 0, 0, 0, 0, 'Very recently, I was walking in the Waxwood, when one of these sprites got on all fours behind my knees, evading my notice. Soon afterward, a second sprite approached me from the front, shoving me forcefully in the chest. Unaware of the first sprite, I stepped backwards, only to stumble on his prostrate form and fall, embarrassingly, onto my backside.$b$bSo yes, I have a vested interest in this assignment.', 27326), -- And a Heavy Fist
(29629, 0, 0, 0, 0, 'It is said that the ancient herbalism masters were able to remove 20 vials of extract from each blossom.', 27326), -- A Steady Hand
(29628, 0, 0, 0, 0, 'She really is a nice woman. And an excellent cook.$b$bThe best cook in the world, actually.', 27326), -- A Strong Back
(29627, 0, 0, 0, 0, '<Wu looks at you expectantly.>', 27326), -- A Proper Weapon
(29635, 0, 0, 0, 0, 'Young Xiao has a great future in martial arts. I wish you luck in your upcoming match.', 27326), -- Xiao, the Eater
(29634, 0, 0, 0, 0, 'I do not know why he decided to take the monastic path so late in life. It is not my place to ask. Such questions fall under the responsibility of our Spirit-Sage.', 27326), -- Husshun, the Wizened
(29633, 0, 0, 0, 0, 'Zhi-Zhi\'s style is different than that of most pandaren monks. He and his kind tend to have more... energy... than us.', 27326), -- Zhi-Zhi, the Dextrous
(29632, 0, 0, 0, 0, 'You may be a hero in your own lands, but here, you must prove your worth.', 27326), -- Becoming Battle-Ready
(29620, 0, 0, 0, 0, 'We will move on to the training soon enough, young $c. First, we must talk, and drink, and eat.$b$bThough I must say, I admire your discipline.', 27326), -- The Great Banquet
(29619, 0, 0, 0, 0, 'Are you ready for the banquet? I can\'t wait.', 27326), -- A Courteous Guest
(29756, 0, 0, 0, 0, 'Even the dead know hunger.', 27326), -- A Humble Offering
(29753, 0, 0, 0, 0, 'Do not fear for the spirits of the beasts - they will find peace here.', 27326), -- Back to Nature
(29752, 0, 0, 0, 0, 'We mustn\'t forsake the wayward dead.', 27326), -- The Wayward Dead
(29750, 0, 0, 0, 0, 'To think the mogu have continued training the Spiritclaws for all these years...$B$BDid you get the bottles?', 27326), -- Vessels of the Spirit
(29751, 0, 0, 0, 0, 'Have you found the items we need for the ritual? We cannot guide these spirits back without them.', 27326), -- Ritual Artifacts
(29749, 0, 0, 0, 0, 'Spirit-binding! How can the mogu have been allowed to resume such a disgusting practice?! And now here I am, the product of a half-failed conjuring...$B$B<The spirit fumes for a moment, then turns to you.>$B$BWhat century is this?', 0), -- An Urgent Plea
(29926, 0, 0, 0, 0, 'Never thought nibblers would be a big enough threat to choke up the whole mine.', 27326), -- Calamity Jade
(29928, 0, 0, 0, 0, '<Mann looks at you expectantly, eyes wide and nostrils flared.>', 27326), -- I Have No Jade And I Must Scream
(29925, 0, 0, 0, 0, 'Ah, hello again, $p! You received my message, then?', 0), -- All We Can Spare
(31613, 0, 0, 0, 0, 'Sprites, jade destroyers, rocks that talk. This world is becoming a troublesome one.$b$bBut... nothing that can not be solved with a strong brew and winning smile.$b$bAnd a solid punch or two.', 27326), -- Volatile Greenstone Brew
(29920, 0, 0, 0, 0, 'Each of the pandriarchs earned their reputation in life and retained them afterward.  I can\'t even imagine how you will defeat them.', 27326), -- Getting Permission
(29881, 0, 0, 0, 0, 'There is only a small window of time after each petal falls that it may be used to achieve the perfect hue.', 27326), -- The Perfect Color
(29882, 0, 0, 0, 0, 'Have you been able to acquire some stingers? I would normally ask a monk for help with this but they all seem to be elsewhere at the moment.', 27326), -- Quill of Stingers
(29717, 0, 0, 0, 0, 'Wow! You are tough!', 27326), -- Down Kitty!
(29866, 0, 0, 0, 0, 'Did you find the Silkwood?', 27326), -- The Threads that Stick
(29865, 0, 0, 0, 0, 'The silkwood stalkers are not in balance with nature. Predators are one thing but these creatures kill for pleasure. Harmony must be restored.', 27326), -- The Silkwood Road
(29716, 0, 0, 0, 0, 'Where is Shin? I didn\'t see Shin.', 27326), -- The Double Hozen Dare
(31230, 0, 0, 0, 0, 'Any luck?', 27326), -- Welcome to Dawn's Blossom
(29900, 0, 0, 0, 0, 'Did you... find the scroll?', 0), -- An Ancient Legend
(29899, 0, 0, 0, 0, 'The howls are lessening... already.', 27326), -- Rest in Peace
(29898, 0, 0, 0, 0, 'Perhaps I could bring some of these healing waters back to Stormwind with me.', 27326), -- Sacred Waters
(29893, 0, 0, 0, 0, 'Have you collected all the ingredients? It is almost time to make the Dream Brew.', 0), -- Hue
(29892, 0, 0, 0, 0, 'Watch your step in the swamp, my new friend.', 0), -- Body
(29891, 0, 0, 0, 0, 'The mists seem to have a mind of their own, do they not?', 0), -- Potency
(31130, 0, 420, 0, 0, 'There is nothing like a little manual labor to bring strangers together, don\'t you think?', 27326), -- A Visit with Lorewalker Cho
(29904, 0, 0, 0, 0, 'How are those trainees looking?', 27326), -- Bigger Fish to Fry
(29903, 0, 0, 0, 0, 'The jinyu are skilled in different ways. It is up to us to find their strengths.', 27326), -- A Perfect Match
(29887, 0, 0, 0, 0, 'The Elder is a Waterspeaker. He speaks to the waters, and they answer.', 27326), -- The Elder's Instruments
(29762, 0, 0, 0, 0, 'We still grieve for our fallen brothers.', 27326), -- Family Heirlooms
(29885, 0, 0, 0, 0, 'Time is short. Each hour we delay, the White Pawn may move further away.$B$BWhere are the supplies I asked for?', 27326), -- Road Rations
(29883, 0, 0, 0, 0, 'If we can win over the jinyu, they may allow us to stay.', 27326), -- The Pearlfin Situation
(29759, 0, 0, 0, 0, 'Did you find him?', 27326), -- Kung Din
(29560, 0, 0, 0, 0, 'The skulls are precious to my tribe. How many have you collected?', 27326), -- Ancient Power
(29559, 0, 0, 0, 0, 'Are they freed?', 27326), -- Freeing Our Brothers
(29558, 0, 0, 0, 0, 'You fight well, foreigner.', 27326), -- The Path of War
(29555, 0, 0, 0, 0, 'Well?', 0), -- The White Pawn
(31744, 0, 0, 0, 0, 'Those poor, wee little cubs. Go, help \'em out, $n. Do what\'s right.', 27326), -- Unfair Trade
(31741, 0, 0, 0, 0, 'Gol\' dang, but there\'s a bunch of \'em down there...', 27326), -- Twinspire Keep
(31743, 0, 0, 0, 0, 'What\'s that you\'ve got, $glad:lass;? Some kind o\' flare?$b$bShoot, I coulda put together a better flare\'n that in half a wink, if Rell had only asked.', 27326), -- Smoke Before Fire
(31742, 0, 0, 0, 0, 'Pretty scary-lookin\' characters around here...', 27326), -- Fractured Forces
(31738, 0, 0, 0, 0, 'It is easier to harbor hatred than to make peace.', 27326), -- Pillaging Peons
(29552, 0, 0, 0, 0, 'We will remember all the brave Alliance soldiers who fell today. Though they can no longer continue, we carry the fight onward.', 27326), -- Critical Condition
(31735, 0, 0, 0, 0, 'We will complete our mission, but right now our priority is that warlock!', 27326), -- The Right Tool For The Job
(31732, 0, 5, 0, 0, 'What are you waiting for?! Scorch the ground beneath them!', 27326), -- Unleash Hell
(29548, 0, 273, 0, 0, 'Ah, a veteran of the Cataclysm campaigns! Good, I could use more experienced hands.', 27326), -- The Mission
(27702, 0, 396, 0, 0, 'Finish off more Twilight Skyterrors.', 27326), -- Coup de Grace
(27700, 0, 396, 0, 0, 'Use the axe to break Lirastrasza\'s chains.', 27326), -- Dragon, Unchained
(27695, 6, 6, 0, 0, 'Do you have the axe? They\'re going to kill Lirastrasza soon.', 27326), -- The Elementium Axe
(27688, 0, 274, 0, 0, 'They\'re not all dead yet.', 27326), -- Distract Them for Me
(27654, 0, 396, 0, 0, 'Looks to me like you might need to take out a few more. I\'m just saying.', 27326), -- Bring the Hammer Down
(27652, 6, 6, 0, 0, 'How many pendants do you have?', 27326), -- Dark Assassins
(27500, 25, 0, 0, 0, 'Is that blood dripping from your pack?', 0), -- Four Heads are Better than None
(27490, 0, 25, 0, 0, 'I need you to escort those SI:7 agents safely to their destination, $n.', 27326), -- SI:7 Drop
(27496, 0, 25, 0, 0, 'I need you to go back to the Twilight Gate and mark those buildings for bombardment.', 27326), -- Call in the Artillery
(27492, 0, 6, 0, 0, 'What\'s the matter? You Alliance $g boys : girls; don\'t have the stomach to get the job done?$B$B<Kurdran gives you a wink.>$B$BNeed me to fly over there and kill them for you?', 27326), -- Ogres & Ettins
(28103, 0, 1, 0, 0, 'There are still some guards left down there. Clean them out.', 27326), -- Easy Pickings
(28104, 1, 1, 0, 0, 'They\'ve grown overconfident. More and more, that seems the downfall of the most powerful armies.', 27326), -- Precious Goods
(28655, 0, 11, 0, 0, 'It\'s a nice day for a Wild wedding...', 27326), -- Wild, Wild, Wildhammer Wedding
(28411, 6, 6, 0, 0, 'What\'s the food situation, $n?', 27326), -- Something Stewed
(28410, 6, 6, 0, 0, 'How did the air raid go?', 27326), -- Something Stolen
(28409, 0, 6, 0, 0, 'Is the road clear? Or were the Dragonmaw causing trouble again?', 27326), -- Something Brewed
(28408, 6, 6, 0, 0, 'Have you Fanny\'s feathers?', 27326), -- Something Bold
(28413, 0, 273, 0, 0, '\"Words and Music by Russell Brower the Bard and $n the $C.\"$B$BThat\'s got a ring to it.', 27326), -- Words and Music By...
(28379, 0, 6, 0, 0, 'Walp? Got a few more notches on yer weapon to show off?', 27326), -- Ogre Bashin'
(28378, 0, 0, 0, 0, 'Do you see that? The Firebeards are supporting us from the air. It\'s about time.$B$BHave you found my sister yet?', 27326), -- Find Fanny
(28244, 0, 6, 0, 0, 'Whad\'ya see, $c?', 27326), -- Eye Spy
(28243, 6, 0, 0, 0, 'You again? Wot? You bring me somethun\'?', 0), -- The Eyes Have It
(28280, 0, 6, 0, 0, 'You\'re still alive!$B$BWait, I\'m sorry, I didn\'t mean to sound so surprised.', 27326), -- Tear Them From the Sky!
(28242, 0, 0, 0, 0, 'I have been watching you, $r.', 27326), -- We All Must Sacrifice
(28215, 6, 6, 0, 0, 'If you start pulling heaps of elementium coils out of your backpack right now, you\'re going to make me one happy gnome!', 27326), -- Potential Energy
(28212, 6, 6, 0, 0, 'Do you have the molten fury? No no, don\'t put it in my hand. Here, use the tongs!', 27326), -- Hot Stuff
(28211, 6, 6, 0, 0, 'Spears, yes? My rapid-fire speargun would be rendered ineffective without them.', 27326), -- Tempered in Elemental Flame
(28216, 274, 274, 0, 0, 'All these years ol\' Humboldt thought his worst problems were from the Glopgut ogres up on the ridge. Then the Twilight\'s Hammer came.$B$BIn an instant, they set the whole valley ablaze like it were a birthday cake. Heartless.', 27326), -- Magmalord Falthazar
(27752, 6, 6, 0, 0, 'Get me that ale, $n.$B$BHey, you haven\'t been skimmin\' off the top, have you?', 27326), -- Fight Like a Wildhammer
(27753, 6, 6, 0, 0, 'Got some eats?', 27326), -- Never Leave a Dinner Behind
(27754, 6, 6, 0, 0, 'How goes the fight, $c?', 27326), -- Dragonmaw Takedown
(27651, 0, 1, 0, 0, '', 27326), -- Doing It Like a Dunwald
(27649, 1, 1, 0, 0, 'Where\'s me booze?', 27326), -- A Steady Supply
(27647, 5, 0, 0, 0, 'You stink of sober! Find me some drink!', 0), -- Anything But Water
(27646, 0, 6, 0, 0, 'Did you find\'m?! Please?', 27326), -- Finding Beak
(27648, 0, 5, 0, 0, 'They keep comin an\' I\'ll keep swinging!', 27326), -- Once More Into The Fire
(27641, 0, 0, 0, 0, 'Have you delivered that message for me?', 27326), -- While Meeting The Family
(27642, 0, 0, 0, 0, 'What\'s the news, $r?', 27326), -- Sifting Through The Wreckage
(27817, 0, 1, 0, 0, 'Today is the day that the tables turn.', 27326), -- Dropping the Hammer
(27811, 0, 1, 0, 0, 'We\'re not going to be much use to you without our birds.', 27326), -- The Scent of Battle
(27810, 0, 1, 0, 0, 'Naw, I\'ll not be fightin\' ya. Get in there and challenge one of my boys if you\'ve got a gut on ya at all.', 27326), -- The Fighting Spirit
(27815, 0, 0, 0, 0, 'What have we here?', 0), -- Somethin' for the Boys
(27813, 0, 1, 0, 0, 'Clear this place out for me yet? Not lookin\' like it.', 27326), -- Death Worthy of a Dragonmaw
(27805, 1, 1, 0, 0, 'Were you able to find their valuables? I know it seems so minor, but little things make a big difference to some people in times like these.', 27326), -- Small Comforts
(27804, 0, 396, 0, 0, 'As long as we work together, we can overcome anything the Twilight\'s Hammer might throw at us.', 27326), -- The Only Homes We Have
(27803, 0, 396, 0, 0, 'Don\'t be dallyin\'. These men are pourin\' every fiber of their bein\' into holding this town, and I\'ll not see them insulted by the presence of anyone that won\'t hold their weight.', 27326), -- Welcome Relief
(27537, 6, 0, 0, 0, 'Hello, $c. Kurdran tells me you\'ve got a solution to getting this portal opened?', 0), -- Any Portal in a Storm
(27515, 6, 6, 0, 0, 'Didja get me roots, $c? Well?', 27326), -- Roots'll Do 'Er
(27468, 274, 274, 0, 0, 'Rocks an\' stumps an\' hills an\' mud... Bah.$B$BI hate nature.', 27326), -- Siege Tank Rescue
(27433, 6, 6, 0, 0, 'What\'d you get me, $n?', 27326), -- Shredderectomy
(27366, 0, 0, 0, 0, 'You\'re still alive, $n.$B$BAre they?', 27326), -- Landgrab
(27341, 0, 6, 0, 0, 'What\'s the word out there, $n?', 27326), -- Scouting the Shore
(27178, 0, 273, 0, 0, 'You\'re soaked, mate.', 27326), -- Naga Reinforcements
(28596, 0, 1, 0, 0, 'You\'ll have to kill a few more than that, soldier.', 27326), -- Welcome to Highbank!
(29329, 0, 0, 0, 0, 'We are nearly there, $n. Stay by my side a bit longer. We will get through to him yet.', 27326); -- Elemental Bonds: Patience

UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=27538; -- The Perfect Poultice
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=27326 WHERE `ID`=27177; -- Salvage Operation
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=27326 WHERE `ID`=28598; -- Aiming High
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=28597; -- Burnin' at Both Ends

UPDATE `quest_request_items` SET `VerifiedBuild`=27326 WHERE `ID` IN (28234, 27814);

DELETE FROM `quest_request_items` WHERE `ID` IN (30032 /*The Quest for Better Barley*/, 30028 /*Grain Recovery*/, 30030 /*Out of Sprite*/, 30029 /*Wee Little Shenanigans*/, 30031 /*Taste Test*/, 30052 /*Weed War*/, 30050 /*Gardener Fran and the Watering Can*/, 30054 /*Enough is Ookin' Enough*/, 30051 /*The Great Water Hunt*/, 30257 /*Learn and Grow V: Halfhill Market*/, 30256 /*Learn and Grow IV: Harvesting*/, 30254 /*Learn and Grow II: Tilling and Planting*/, 30535 /*Learn and Grow I: Seeds*/, 32045 /*Children of the Water*/, 31281 /*So You Want to Be a Chef...*/, 31486 /*Everything I Know About Cooking*/, 30252 /*A Helping Hand*/, 32685 /*No Fishing Pole Necessary!*/, 30058 /*Mothallus!*/, 30072 /*Where Silk Comes From*/, 29581 /*The Golden Dream*/, 29600 /*Snap Judgment*/, 29577 /*Ashyo's Vision*/, 30267 /*Watery Woes*/, 29757 /*Bottletoads*/, 29952 /*Broken Dreams*/, 29951 /*Muddy Water*/, 29948 /*Thieves to the Core*/, 29947 /*Crouching Carrot, Hidden Turnip*/, 29946 /*The Warren-Mother*/, 29945 /*Yellow and Red Make Orange*/, 29944 /*Leaders Among Breeders*/, 31285 /*The Spring Drifter*/, 31287 /*Educating Saurok*/, 31286 /*Robbing Robbers of Robbers*/, 29918 /*A Lesson in Bravery*/, 29917 /*Lupello*/, 29916 /*Piercing Talons and Slavering Jaws*/, 29915 /*A Neighbor's Duty*/, 29914 /*Back to the Sty*/, 29913 /*The Meat They'll Eat*/, 29911 /*Practically Perfect Produce*/, 29910 /*Rampaging Rodents*/, 29940 /*Taking a Crop*/, 29877 /*A Poor Grasp of the Basics*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(30032, 0, 0, 0, 0, 'That jungle sounds spooky.', 27356), -- The Quest for Better Barley
(30028, 0, 0, 0, 0, 'Between birds and sprites we are never going to meet our quota to the Stormstout Brewery.', 27356), -- Grain Recovery
(30030, 0, 0, 0, 0, 'Oh why? Why did I have to tamper with the natural order of things? All I wanted was to make these grains grow faster and more numerous.', 27356), -- Out of Sprite
(30029, 0, 0, 0, 0, 'Oh good, they didn\'t turn you into a frog yet. I saw them do that once you know.', 27356), -- Wee Little Shenanigans
(30031, 0, 0, 0, 0, 'None of this seems to taste sweet enough! What\'s the deal?', 27356), -- Taste Test
(30052, 0, 0, 0, 0, '', 27356), -- Weed War
(30050, 0, 0, 0, 0, 'Water my plants you lazy $c!', 27356), -- Gardener Fran and the Watering Can
(30054, 0, 0, 0, 0, 'You bring back those teeth, and maybe Mung-Mung will have some hops for you.', 27356), -- Enough is Ookin' Enough
(30051, 0, 0, 0, 0, 'That Stormstout feller says that he\'s the best brewer that ever was. Might be true, couldn\'t tell ya one way or the \'nother as of yet.', 27356), -- The Great Water Hunt
(30257, 0, 0, 0, 0, 'Hey, haven\'t seen your face around here before! What\'s your name?', 0), -- Learn and Grow V: Halfhill Market
(30256, 0, 0, 0, 0, 'Look at those... err, what do they say around here? Oh yeah, b\'yoots!$B$BLook at those b\'yoots!$B$BI think I\'m getting the hang of this farmer thing.', 27356), -- Learn and Grow IV: Harvesting
(30254, 0, 0, 0, 0, 'Well, go ahead - bust that soil up and plant the seeds!$B$BYou aren\'t giving up already are you? I need your help!', 27356), -- Learn and Grow II: Tilling and Planting
(30535, 0, 0, 0, 0, 'How\'d it go, partner? Did you get those seeds from Groanfur?$B$BErr... Greenfield?', 27356), -- Learn and Grow I: Seeds
(32045, 0, 0, 0, 0, '', 27356), -- Children of the Water
(31281, 0, 0, 0, 0, 'Show me that you can follow instructions.', 0), -- So You Want to Be a Chef...
(31486, 0, 0, 0, 0, 'You have a letter for me?', 0), -- Everything I Know About Cooking
(30252, 0, 0, 0, 0, 'I really wasn\'t cut out for this type of work. I didn\'t exactly grow up in the country.', 27356), -- A Helping Hand
(32685, 0, 0, 0, 0, 'Catch 5 Golden Carp. Try it without a fishing pole!', 0), -- No Fishing Pole Necessary!
(30058, 0, 0, 0, 0, 'Have you vanquished the beast?', 27356), -- Mothallus!
(30072, 0, 0, 0, 0, 'Have you found all of the items? Did you pay close attention to our process?', 27356), -- Where Silk Comes From
(29581, 0, 0, 0, 0, 'Yes, did you need something?', 0), -- The Golden Dream
(29600, 0, 0, 0, 0, '<Yue sighs.>$B$BIf only we\'d kept up with our maintenance, the situation would not have come to this.', 27356), -- Snap Judgment
(29577, 0, 0, 0, 0, 'What is that jinyu up to over there?', 27356), -- Ashyo's Vision
(30267, 0, 0, 0, 0, 'I refuse to not fish. Fishing\'s who I am!', 27356), -- Watery Woes
(29757, 0, 0, 0, 0, '\"It just ain\'t a party without Bottletoads!\"$B$BHmm... no, that doesn\'t work.$B$B\"Bottletoads: not as gross as they sound!\"', 27356), -- Bottletoads
(29952, 0, 0, 0, 0, '...', 27356), -- Broken Dreams
(29951, 0, 0, 0, 0, 'I knowed you for a friend as soon as I seen you.', 27356), -- Muddy Water
(29948, 0, 0, 0, 0, 'I done told those virmen to stay off my land.', 27356), -- Thieves to the Core
(29947, 0, 0, 0, 0, 'Go, torment those virmen, $n!', 27356), -- Crouching Carrot, Hidden Turnip
(29946, 0, 0, 0, 0, 'Ready when you are, $n.$b$bYou go ahead. I\'ll meet you down there.', 27356), -- The Warren-Mother
(29945, 0, 0, 0, 0, 'You have the stuff ready for the paint? I went ahead and gathered some turnips.', 27356), -- Yellow and Red Make Orange
(29944, 0, 0, 0, 0, 'The virmen here have strange habits. Stranger names.', 27356), -- Leaders Among Breeders
(31285, 0, 0, 0, 0, 'It is always good luck to have a grummle aboard when traveling through a saurok infested cave.', 27356), -- The Spring Drifter
(31287, 0, 0, 0, 0, 'It is unwise to challenge the domain of Madam Goya.', 27356), -- Educating Saurok
(31286, 0, 0, 0, 0, 'Saurok are seldom this bold.', 27356), -- Robbing Robbers of Robbers
(29918, 0, 0, 0, 0, 'You lack fear. I can sense it in your heart.', 0), -- A Lesson in Bravery
(29917, 0, 0, 0, 0, 'What will Master Shang say when he finds out?', 27356), -- Lupello
(29916, 0, 18, 0, 0, 'I wish I were brave enough to fight them, but...', 27356), -- Piercing Talons and Slavering Jaws
(29915, 0, 0, 0, 0, 'Oh... you have one of my... my lambs?', 0), -- A Neighbor's Duty
(29914, 0, 0, 0, 0, 'Have you found them? There should be three missing, I think.', 27356), -- Back to the Sty
(29913, 0, 0, 0, 0, 'It hurts my ears to hear their hungry squeals.$b$bOnce you\'ve been a pig rancher for a while, you can distinguish hungry squeals from regular squeals.', 27356), -- The Meat They'll Eat
(29911, 0, 0, 0, 0, 'Do I smell turnips?', 0), -- Practically Perfect Produce
(29910, 0, 0, 0, 0, 'The marmots won\'t be happy when you try to fill in their holes.', 27356), -- Rampaging Rodents
(29940, 0, 0, 0, 0, 'If my father wants his vegetables, I\'m going to need your help.', 27356), -- Taking a Crop
(29877, 0, 0, 0, 0, 'Man, those virmen is dumb.', 27356); -- A Poor Grasp of the Basics

DELETE FROM `quest_request_items` WHERE `ID` IN (30625 /*Students No More*/, 30622 /*The Swarm Begins*/, 30675 /*Buried Hozen Treasure*/, 30691 /*Misery*/, 30671 /*Wisdom Has A Price*/, 30668 /*Build Your Own Raft*/, 30666 /*Sudden, Unexpected Crocolisk Aggression*/, 30667 /*Particular Plumage*/, 31058 /*The Funky Monkey Brew*/, 30359 /*The Lord Reclaimer*/, 30361 /*The Mantid*/, 30357 /*The Stoneplow Convoy*/, 30355 /*Re-Reclaim*/, 30356 /*Sever Their Supply Line*/, 30354 /*No Sister Left Behind*/, 30363 /*Going on the Offensive*/, 30169 /*Raid Leader Slovan*/, 30168 /*Thieving Raiders*/, 30272 /*Striking the Rain*/, 30695 /*Ahead on the Way*/, 30271 /*Sha Can Awe*/, 30268 /*The Murksweats*/, 30694 /*Tread Lightly*/, 30270 /*Blinding the Riverblades*/, 30351 /*Lotus Tea*/, 30347 /*The Pools of Youth*/, 30349 /*Threat from Dojan*/, 30346 /*Where are the Pools*/, 30384 /*Blind Them!*/, 30350 /*Squirmy Delight*/, 30344 /*The Lost Dynasty*/, 31262 /*Crane Mastery: Needlebeak*/, 31260 /*Profit Mastery: Chasheen*/, 30353 /*Profit Mastery*/, 30352 /*Crane Mastery*/, 30089 /*Apply Directly to the Forehead*/, 30088 /*Why So Serious?*/, 30083 /*Securing the Province*/, 30081 /*Materia Medica*/, 30091 /*Tears of Pandaria*/, 30079 /*What's Eating Zhu's Watch?*/, 29989 /*Unyielding Fists: Trial of Stone*/, 29988 /*A Taste For Eggs*/, 29987 /*Unyielding Fists: Trial of Wood*/, 29992 /*Tenderpaw By Name, Tender Paw By Reputation*/, 29986 /*Fog Wards*/, 29985 /*They Will Be Mist*/, 29984 /*Unyielding Fists: Trial of Bamboo*/, 29982 /*Evacuation Orders*/, 29981 /*Stemming the Swarm*/, 30117 /*Stoneplow Thirsts*/, 30185 /*Tortoise Mastery*/, 32038 /*Stag Mastery*/, 30182 /*Fox Mastery*/, 30184 /*Mushan Mastery: Darkhide*/, 30183 /*Stalker Mastery*/, 30181 /*Mushan Mastery*/, 30078 /*Cleaning House*/, 30076 /*The Fanciest Water*/, 30077 /*Barrels, Man*/, 30075 /*Clear the Way*/, 31945 /*Learn and Grow VI: Gina's Vote*/, 30073 /*The Emperor*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(30625, 0, 0, 0, 0, '', 27366), -- Students No More
(30622, 0, 0, 0, 0, 'Look at the SIZE of that thing...', 27366), -- The Swarm Begins
(30675, 0, 0, 0, 0, 'This must be it!', 0), -- Buried Hozen Treasure
(30691, 0, 0, 0, 0, 'Please, $n. Even the great beasts of this world have a right to die in dignity.', 27366), -- Misery
(30671, 0, 0, 0, 0, 'My hunger is great, $r. I have been on this lagoon for several days, without food.', 27366), -- Wisdom Has A Price
(30668, 0, 0, 0, 0, 'You got the stuff? I\'ll build your raft, I just need materials.', 27366), -- Build Your Own Raft
(30666, 0, 0, 0, 0, 'What would make the crocs attack like this?', 27366), -- Sudden, Unexpected Crocolisk Aggression
(30667, 0, 0, 0, 0, '<A bead of sweat twinkles in the fur above Tony\'s brow.>', 27366), -- Particular Plumage
(31058, 0, 0, 0, 0, 'These hozen pack some mean toys and some meaner brews.', 27366), -- The Funky Monkey Brew
(30359, 0, 0, 0, 0, 'Lyalia is the only family I have left. I had to bury her mother during the war of Ahn\'Qiraj.', 27366), -- The Lord Reclaimer
(30361, 0, 0, 0, 0, 'It has been many thousands of years since mantid were seen on this side of the Great Wall.', 27366), -- The Mantid
(30357, 0, 0, 0, 0, 'These mantid are a much bigger threat than I think even the pandaren give them credit for.', 27366), -- The Stoneplow Convoy
(30355, 0, 0, 0, 0, 'Every artifact in our possession is one less weapon in mogu hands.', 27366), -- Re-Reclaim
(30356, 0, 0, 0, 0, 'We cannot hope to beat these mogu if their numbers keep growing.', 27366), -- Sever Their Supply Line
(30354, 0, 0, 0, 0, 'I will not have my people condemned to slavery and torture at hands of the mogu.', 27366), -- No Sister Left Behind
(30363, 0, 0, 0, 0, 'Did you find the scout?', 0), -- Going on the Offensive
(30169, 0, 0, 0, 0, 'Slovan has always been a nuisance, but with the Crane Temple\'s defenses down he has become a true threat.', 27366), -- Raid Leader Slovan
(30168, 0, 0, 0, 0, 'I think they even stole my holy spittoon. ', 27366), -- Thieving Raiders
(30272, 0, 0, 0, 0, 'We shouldn\'t press further into the temple before clearing out some of the sha presence outside.', 27366), -- Striking the Rain
(30695, 0, 0, 0, 0, 'Koro said there\'s a pagoda on either side of the temple. Let\'s find them and wipe out the sha presence in both.', 27366), -- Ahead on the Way
(30271, 0, 0, 0, 0, 'Look for Crane Wing pandaren who are falling to despair and slay sha near them while I support you!', 27366), -- Sha Can Awe
(30268, 0, 0, 0, 0, '<Anduin is focused intently on his hands, swiftly carving venom glands from the snakes.>$B$BInside the jaw... two inches behind the second set of fangs...', 27366), -- The Murksweats
(30694, 0, 0, 0, 0, 'Well, I don\'t see any spikes in your face. That\'s a good sign.', 27366), -- Tread Lightly
(30270, 0, 0, 0, 0, 'We cannot risk any more saurok ambushes, but we\'re in no position to take them on in force. Fortunately, with you here, we shouldn\'t need to.', 27366), -- Blinding the Riverblades
(30351, 0, 0, 0, 0, 'I have never seen the mogu this numerous before. They have always been a nuisance but never this bad.', 0), -- Lotus Tea
(30347, 0, 0, 0, 0, 'Nothing like being mortal to give one a sense of urgency.', 27366), -- The Pools of Youth
(30349, 0, 0, 0, 0, 'Kang has been sharing stories with me about these mogu.$b$bApparently ages ago they ruled as emperors subjugating all free races of Pandaria and the surrounding regions. Now they are little more than hoodlums.$b$bTo see these mogu fight though, I suspect they are trying to rekindle some of their older ideals and ambitions.', 27366), -- Threat from Dojan
(30346, 0, 0, 0, 0, '<You sense the presence of Lorekeeper Vaeldrin, then hear his voice within your mind.>$b$bHmm. I\'m still not sure about these references to \"torture\" regarding the Pools of Youth.', 27366), -- Where are the Pools
(30384, 0, 0, 0, 0, 'Did you find the tauren scout? Our presence must be kept a secret. The horde can NOT know we are here.', 27366), -- Blind Them!
(30350, 0, 0, 0, 0, 'Mama Bramblestaff always said Squirmy Delight will cure any hunger one way or another.', 27366), -- Squirmy Delight
(30344, 0, 0, 0, 0, 'It is one thing to research the lost dynasties. It is quite another to visit their ancient ruins.$b$bI am giddy as I have not felt in centuries!', 27366), -- The Lost Dynasty
(31262, 0, 0, 0, 0, 'I watched that bird stab a tiger through the face. What kind of place is this where birds are the predators for tigers?', 27366), -- Crane Mastery: Needlebeak
(31260, 0, 0, 0, 0, 'I thought about taking that tiger on myself but to be honest I like living...', 27366), -- Profit Mastery: Chasheen
(30353, 0, 0, 0, 0, 'I like hunting with Nesingwary and all but he\'s in it for the hunting. I\'m in it for the profit, and he doesn\'t pay us.', 27366), -- Profit Mastery
(30352, 0, 0, 0, 0, 'As far as I\'m concerned, paying you to kill these birds is the same as me shooting them myself. You just get to be my gun as it were.', 27366), -- Crane Mastery
(30089, 0, 0, 0, 0, 'This must be the emperor\'s sad coming back! That is some oooold sad.$B$BKen-Ken bet pandaren sad get stronger with age, too, like pandaren booze.', 27366), -- Apply Directly to the Forehead
(30088, 0, 0, 0, 0, '<Ken-Ken is hard at work carving something out of tree bark.>$B$BThis gonna be great, you\'ll see.', 27366), -- Why So Serious?
(30083, 0, 0, 0, 0, 'We cannot let the saurok walk all over us anymore.', 27366), -- Securing the Province
(30081, 0, 0, 0, 0, 'Can\'t believe Ken-Ken did not think of this sooner. It\'s the ONE thing that can ruin his day...', 27366), -- Materia Medica
(30091, 0, 0, 0, 0, 'I don\'t know why this is happening, but I can say for certain that those elementals were the start of it all.', 27366), -- Tears of Pandaria
(30079, 0, 0, 0, 0, 'Something definitely not right! Pandaren supposed to be HAPPY!', 27366), -- What's Eating Zhu's Watch?
(29989, 0, 0, 0, 0, 'This test will be trying. You will test the strength of your fists against the strength of stone. Steel yourself, $n.$b$bNot literally, of course.$b$bUnless you normally wear steel gloves... in which case, you may literally steel yourself.', 27366), -- Unyielding Fists: Trial of Stone
(29988, 6, 6, 0, 0, 'How is your egg hunt going?', 27366), -- A Taste For Eggs
(29987, 0, 0, 0, 0, 'I\'m prepared, $n. Are you?', 27366), -- Unyielding Fists: Trial of Wood
(29992, 0, 0, 0, 0, 'Ow! Ow! Ow!', 27366), -- Tenderpaw By Name, Tender Paw By Reputation
(29986, 0, 0, 0, 0, 'See if you can light one of the wards while one of the mist incarnations is nearby.', 27366), -- Fog Wards
(29985, 0, 0, 0, 0, 'Living outside of society has its advantages. I can focus all my energies on training, without being shackled to the societal conventions of modesty, politics, and basic personal hygiene. Here in the woods, I am free to be myself.', 27366), -- They Will Be Mist
(29984, 0, 0, 0, 0, 'If you cannot pass this test, then there is probably no reason to continue our training.', 27366), -- Unyielding Fists: Trial of Bamboo
(29982, 0, 0, 0, 0, 'Once these mantid are slain, we can get to work repairing the wall and restoring the town to its normal state.', 27366), -- Evacuation Orders
(29981, 0, 0, 0, 0, 'If the flying mantid troops have always been able to fly over, why haven\'t they before now?', 27366), -- Stemming the Swarm
(30117, 0, 0, 0, 0, 'Greetings, $c.', 0), -- Stoneplow Thirsts
(30185, 0, 0, 0, 0, 'I\'ve always been livin\' in me father\'s shadow. But after today, folks are gonna remember the name of Nesingwary, Jr.!', 27366), -- Tortoise Mastery
(32038, 0, 0, 0, 0, 'How goes the hunt?', 27366), -- Stag Mastery
(30182, 0, 0, 0, 0, 'I used to go on fox hunts with my father. If he could see me now! Hunting in Pandaria!', 27366), -- Fox Mastery
(30184, 0, 0, 0, 0, 'Puttin\' the \"big\" into \"Big Game Hunter.\"', 27366), -- Mushan Mastery: Darkhide
(30183, 0, 0, 0, 0, 'What\'s your count up to?', 27366), -- Stalker Mastery
(30181, 0, 0, 0, 0, 'They didn\'t send ya\' runin\' did they?', 27366), -- Mushan Mastery
(30078, 0, 0, 0, 0, 'Let\'s do this.', 27366), -- Cleaning House
(30076, 5, 5, 0, 0, 'This is gonna be great. It\'ll be just like makin\' beer, but instead of water, I\'m gonna use water sprite meat.', 27366), -- The Fanciest Water
(30077, 0, 0, 0, 0, 'Barrels.', 27366), -- Barrels, Man
(30075, 0, 0, 0, 0, 'This brewery - it\'s a disgrace to the Stormstout name! Something needs to be done!', 27366), -- Clear the Way
(31945, 0, 0, 0, 0, 'Don\'t overlook the scallion. It may be small and innocuous, but it creates truly marvelous flavors.', 0), -- Learn and Grow VI: Gina's Vote
(30073, 0, 0, 0, 0, 'It takes more than three seconds to make beer, $n. Even when your name is Chen Stormstout.', 27366); -- The Emperor

DELETE FROM `quest_request_items` WHERE `ID` IN (31606 /*The Dissector Wakens*/, 31189 /*Reeltime Strategy*/, 31186 /*Dog Food*/, 31188 /*Shark Week*/, 31187 /*On the Crab*/, 31184 /*Old Age and Treachery*/, 31185 /*Walking Dog*/, 31182 /*You Otter Know*/, 31181 /*Fresh Pots*/, 31265 /*Mazu's Breath*/, 31178 /*A Bloody Delight*/, 31177 /*Fine Dining*/, 31176 /*A Strange Appetite*/, 31085 /*Fires and Fears of Old*/, 31086 /*Blood of Ancients*/, 31084 /*Bind the Glamour*/, 31082 /*Great Vessel of Salvation*/, 31080 /*Fiery Wings*/, 31079 /*The Horror Comes A-Rising*/, 31078 /*Han Stormstout*/, 31133 /*Kor'thik Aggression*/, 31129 /*Fate of the Stormstouts*/, 31074 /*Wood and Shade*/, 31073 /*Bound With Wood*/, 31071 /*I Bring Us Great Shame*/, 31070 /*Daggers of the Great Ones*/, 31069 /*Bound With Shade*/, 31072 /*Rending Daggers*/, 31068 /*Sacred Recipe*/, 31067 /*The Heavens Hum With War*/, 31023 /*Relics of the Swarm*/, 31026 /*The Root of the Problem*/, 31022 /*Kypari Zar*/, 31021 /*Living Amber*/, 31020 /*Feeding the Beast*/, 31398 /*Falling to Pieces*/, 31090 /*Better With Age*/, 31088 /*Crime and Punishment*/, 31107 /*Citizens of a New Empire*/, 31066 /*A Cry From Darkness*/, 31108 /*Concentrated Fear*/, 31008 /*Amber Arms*/, 31660 /*Not Fit to Swarm*/, 31007 /*The Dread Clutches*/, 31676 /*Ancient Vengeance*/, 31005 /*Wakening Sickness*/, 31110 /*Through the Portal*/, 30928 /*A Trail of Fear*/, 30927 /*Give Them Peace*/, 30930 /*Pick a Yak*/, 30932 /*Father's Footsteps*/, 30925 /*Niuzao's Price*/, 30929 /*Bad Yak*/, 30931 /*My Father's Crossbow*/, 31809 /*Remnants of Anger*/, 30964 /*A Proper Poultice*/, 30963 /*The Field Armorer*/, 30922 /*Natural Antiseptic*/, 31688 /*The Search for Restless Leng*/, 31687 /*Thinning the Sik'thik*/, 31065 /*Buried Beneath*/, 30899 /*In Skilled Hands*/, 31032 /*Choking the Skies*/, 30977 /*Grounded Welcome*/, 30973 /*Up In Flames*/, 30972 /*Joining the Fight*/, 30970 /*Enraged By Hatred*/, 30971 /*Taking Stock*/, 30898 /*Cutting the Swarm*/, 30896 /*Thieves and Troublemakers*/, 30897 /*In the Wrong Hands*/, 30895 /*Improvised Ammunition*/, 30894 /*Rummaging Through the Remains*/, 30892 /*Back on Their Feet*/, 30893 /*The Endless Swarm*/, 30890 /*The Restless Watch*/, 30888 /*Breach in the Defenses*/, 30889 /*Trap Setting*/, 30891 /*Treatment for the Troops*/, 30792 /*Orbiss Fades*/, 30791 /*Arconiss Thirsts*/, 30790 /*Golgoss Hungers*/, 30789 /*Arconiss*/, 30788 /*Golgoss*/, 30787 /*The Torches*/, 30786 /*A Spear Through My Side, A Chain Through My Soul*/, 30784 /*The Point of No Return*/, 30783 /*Hatred Becomes Us*/, 30780 /*Totemic Research*/, 30779 /*Slaying the Scavengers*/, 30778 /*Dust to Dust*/, 30776 /*Jung Duk*/, 30775 /*The Exile*/, 30774 /*Ranger Rescue*/, 30773 /*Pitching In*/, 30772 /*Seeing Red*/, 30771 /*Perfect Pitch*/, 30814 /*A Foot in the Door*/, 31394 /*A Celestial Experience*/, 30820 /*A Funeral*/, 30806 /*The Scent of Life*/, 30807 /*By the Falls, For the Fallen*/, 30805 /*Justice*/, 31228 /*Prophet Khar'zul*/, 30946 /*Revelations*/, 31011 /*Enemies At Our Door*/, 30943 /*Handle With Care*/, 30942 /*Make A Fighter Out of Me*/, 30945 /*What's Yours Is Mine*/, 30944 /*It Takes A Village*/, 30802 /*Chasing the Storm*/, 30801 /*Lessons from History*/, 30800 /*Stealing Their Thunder King*/, 30798 /*Breaking the Emperor's Shield*/, 30799 /*The Tomb of Shadows*/, 30797 /*It Was Almost Alive*/, 30796 /*An End to Everything*/, 30829 /*The Tongue of Ba-Shon*/, 30993 /*Where are My Reinforcements?*/, 30991 /*Do a Barrel Roll!*/, 30751 /*A Terrible Sacrifice*/, 30750 /*Off the Wall!*/, 30715 /*A Line Unbroken*/, 30723 /*Honor, Even in Death*/, 30690 /*Unmasking the Yaungol*/, 30665 /*The Defense of Shado-Pan Fallback*/, 30670 /*Turnabout*/, 30747 /*The Burlap Grind*/, 30746 /*A Fair Trade*/, 30744 /*Kota Blend*/, 30743 /*Gourmet Kafa*/, 30742 /*Shut it Down*/, 30745 /*Trouble Brewing*/, 30611 /*Unleash The Yeti!*/, 30610 /*Grummle! Grummle! Grummle!*/, 30608 /*The Snackrifice*/, 30607 /*Hozen Love Their Keys*/, 30604 /*Breaking Broketooth*/, 30600 /*No Pack Left Behind*/, 30599 /*A Monkey Idol*/, 30603 /*The Broketooth Ravage*/, 30683 /*One Traveler's Misfortune*/, 30618 /*Resupplying One Keg*/, 30621 /*They Stole My Luck!*/, 30601 /*Instant Courage*/, 30808 /*A Grummle's Luck*/, 30614 /*Oil Stop*/, 30616 /*Traffic Issues*/, 30804 /*The Fearmaster*/, 30582 /*The Late Mrs. Muskpaw*/, 30491 /*At the Yak Wash*/, 30489 /*Fresh Needle Scent*/, 30651 /*Barrels of Fun*/, 30581 /*... and the Pot, Too!*/, 30571 /*Farmhand Freedom*/, 30595 /*Profiting off of the Past*/, 30593 /*Deanimate the Reanimated*/, 30619 /*Mogu?! Oh No-gu!*/, 30583 /*Blue Dwarf Needs Food Badly*/, 30575 /*Round 'Em Up*/, 30514 /*Challenge Accepted*/, 30512 /*Westwind Rest*/, 30480 /*The Ritual*/, 30967 /*Free the Dissenters*/, 30496 /*The Waterspeaker's Staff*/, 30468 /*Enraged Vengeance*/, 30469 /*Repossession*/, 30459 /*All of the Arrows*/, 30460 /*Hit Medicine*/, 30457 /*Call Out Their Leader*/, 31254 /*The Road to Kun-Lai*/, 31611 /*The Kun-Lai Kicker*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(31606, 0, 0, 0, 0, '<cough cough>$B$BMy head...', 27377), -- The Dissector Wakens
(31189, 0, 0, 0, 0, 'Go give Ju Lien a hand, would ya?', 27377), -- Reeltime Strategy
(31186, 0, 0, 0, 0, '<This has got to be the most pathetic lion seal you\'ve ever seen.>', 27377), -- Dog Food
(31188, 0, 0, 0, 0, 'Having actually seen someone eaten by a thresher, I\'m not sure why you\'d willingly string their teeth around your neck, but whatever.', 27377), -- Shark Week
(31187, 0, 0, 0, 0, 'You smell that, green?$B$B<Arie takes a big, dramatic whiff of rank, fishy air.>$B$BSmells like money!', 27377), -- On the Crab
(31184, 0, 0, 0, 0, 'To be honest, I hope a grouper ate the old charter.$B$BWait, then it might end up here anyway. Dang it!', 27377), -- Old Age and Treachery
(31185, 0, 0, 0, 0, 'Dog deserves all the freedom the sea has to offer him - I\'ve tried to set him free, but he won\'t go.$B$BBest we can do anymore is take him out for walks now and then.', 27377), -- Walking Dog
(31182, 0, 0, 0, 0, 'In the words of my old deck boss: \"Do what I say, \'cause I said it!\"', 27377), -- You Otter Know
(31181, 0, 0, 0, 0, 'What\'s wrong, green? You aren\'t afraid of the dark, icy sea are you?', 27377), -- Fresh Pots
(31265, 0, 0, 0, 0, 'No, I don\'t have a \"chaser!\" Just drink it!', 27377), -- Mazu's Breath
(31178, 0, 0, 0, 0, 'By drinking the blood of your enemies, you acquire their strength.', 27377), -- A Bloody Delight
(31177, 0, 0, 0, 0, 'I have much work to do. The sooner I can fight, the sooner I can return to the Council.', 27377), -- Fine Dining
(31176, 0, 0, 0, 0, 'The juices of the starfish will clear my mind.', 27377), -- A Strange Appetite
(31085, 0, 0, 0, 0, 'Make sure to bring that forked blade with you.', 27377), -- Fires and Fears of Old
(31086, 0, 0, 0, 0, 'Any luck?', 27377), -- Blood of Ancients
(31084, 0, 0, 0, 0, '...', 27377), -- Bind the Glamour
(31082, 0, 0, 0, 0, 'The collection pit is down the hill, just to the west of here.', 27377), -- Great Vessel of Salvation
(31080, 0, 0, 0, 0, 'I haven\'t been able to catch any of those things!', 27377), -- Fiery Wings
(31079, 0, 0, 0, 0, 'We hate being eaten.', 27377), -- The Horror Comes A-Rising
(31078, 0, 0, 0, 0, 'I think I see someone over there, but I can\'t seem to get across these amber beams.', 27377), -- Han Stormstout
(31133, 0, 0, 0, 0, 'Can\'t stand those mantid.', 27377), -- Kor'thik Aggression
(31129, 0, 0, 0, 0, 'You are brave to have come across the wall, $r.', 27377), -- Fate of the Stormstouts
(31074, 0, 0, 0, 0, '<Lya looks concerned.>', 27377), -- Wood and Shade
(31073, 0, 0, 0, 0, 'We don\'t brew with wood here. It gives the brew a harsh, insipid flavor, not unlike that of wine.$b$b<Vu spits.>', 27377), -- Bound With Wood
(31071, 0, 0, 0, 0, 'Did you find them? Can it be?', 27377), -- I Bring Us Great Shame
(31070, 0, 0, 0, 0, 'I wonder how we\'ll mix those things into the brew? Can\'t grind them up - that\'d be too gritty.$b$bMaybe I\'ll just soak \'em for a while.', 27377), -- Daggers of the Great Ones
(31069, 0, 0, 0, 0, 'You needn\'t look far to find shade around here, friend.', 27377), -- Bound With Shade
(31072, 0, 0, 0, 0, 'I think I\'m starting to understand the next few lines of this prophecy, $n.$b$bDo you have the daggers yet?', 27377), -- Rending Daggers
(31068, 5, 0, 0, 0, 'Is that some sort of scroll?$b$bWould you mind if I took a look?', 0), -- Sacred Recipe
(31067, 0, 6, 0, 0, 'Azzix, his name was. I think. Azzix K\'tai.', 27377), -- The Heavens Hum With War
(31023, 0, 0, 0, 0, 'What do you have there?', 0), -- Relics of the Swarm
(31026, 0, 0, 0, 0, 'The swarm knows not of their terrible folly! These precious trees must be protected at all costs!', 27377), -- The Root of the Problem
(31022, 0, 0, 0, 0, 'What has happened to our home? Things feel amiss.', 27377), -- Kypari Zar
(31021, 0, 0, 0, 0, 'Do you understand, Wakener? The amber gives life.', 27377), -- Living Amber
(31020, 0, 0, 0, 0, 'I have been sleeping for many thousands of years. I must regain my strength before rejoining the Council.', 27377), -- Feeding the Beast
(31398, 0, 0, 0, 0, 'Where did you find this?', 0), -- Falling to Pieces
(31090, 1, 1, 0, 0, 'I would go with you to gather amber, but my talents are more useful here.', 27377), -- Better With Age
(31088, 0, 1, 0, 0, 'Have the harvesters been punished?', 27377), -- Crime and Punishment
(31107, 0, 0, 0, 0, 'Kypari Vor was beautiful once. Rich with amber and surrounded by prime hunting grounds.', 27377), -- Citizens of a New Empire
(31066, 0, 0, 0, 0, 'The order stands. Slay the fallen paragon.', 27377), -- A Cry From Darkness
(31108, 0, 0, 0, 0, 'Do you have the crystals?', 27377), -- Concentrated Fear
(31008, 0, 0, 0, 0, 'The bladesworn carry their swords with pride. I want them on my weapon racks!', 27377), -- Amber Arms
(31660, 0, 0, 0, 0, 'Let me know if you want to be dropped into a sea of swarmborn. It would entertain me greatly.', 27377), -- Not Fit to Swarm
(31007, 0, 0, 0, 0, 'They have forsaken our ways and they will pay dearly for it.', 27377), -- The Dread Clutches
(31676, 0, 0, 0, 0, 'The mogu of Clan Gurthan are quilen lords. Do not wake their guardians.', 27377), -- Ancient Vengeance
(31005, 0, 0, 0, 0, 'Without nourishment, I will die where I stand.', 27377), -- Wakening Sickness
(31110, 0, 0, 0, 0, 'Did you find the powders?', 27377), -- Through the Portal
(30928, 0, 0, 0, 0, 'Even among our own order, only a few chosen elders knew of our sacred duty to contain the Sha of Fear.$b$bWhy they chose to tell the yak-keeper, I may never know.', 27377), -- A Trail of Fear
(30927, 0, 0, 0, 0, 'I should have gone with them.', 27377), -- Give Them Peace
(30930, 0, 0, 0, 0, 'See? I told you! No good yaks.', 27377), -- Pick a Yak
(30932, 0, 0, 0, 0, 'Any luck?', 27377), -- Father's Footsteps
(30925, 0, 0, 0, 0, 'Niuzao does not move quickly, nor does he make rash decisions. Perform his task, and give him time to decide.', 27377), -- Niuzao's Price
(30929, 0, 0, 0, 0, 'This yak is not a good yak. Not at all.', 27377), -- Bad Yak
(30931, 0, 0, 0, 0, 'Did... did you find it?', 27377), -- My Father's Crossbow
(31809, 0, 0, 0, 0, '<Ban looks at you with narrowed eyes.>\n\nSomething about you is... different. Changed.', 0), -- Remnants of Anger
(30964, 0, 0, 0, 0, 'Any luck out there, $n?', 27377), -- A Proper Poultice
(30963, 0, 0, 0, 0, 'I refuse to let one of our kind fall just because of a broken set of armor.', 27377), -- The Field Armorer
(30922, 0, 0, 0, 0, 'It\'s messy work, certainly.$b$bNowhere near as messy as digging graves.', 27377), -- Natural Antiseptic
(31688, 0, 6, 0, 0, 'Did you find him?', 27377), -- The Search for Restless Leng
(31687, 0, 6, 0, 0, 'How did it go?', 27377), -- Thinning the Sik'thik
(31065, 0, 1, 0, 0, 'Go. Look.', 27377), -- Buried Beneath
(30899, 1, 0, 0, 0, 'Another wave of fliers approaches. Be ready.', 0), -- In Skilled Hands
(31032, 0, 1, 0, 0, 'Some of them can make it through the smoke, but in small enough numbers that we can easily pick them off.', 27377), -- Choking the Skies
(30977, 0, 1, 0, 0, 'Our vigil continues...', 27377), -- Grounded Welcome
(30973, 0, 1, 0, 0, 'Creative solution.  Lao-Chin impresses.', 27377), -- Up In Flames
(30972, 1, 0, 0, 0, 'Welcome to the mess.', 0), -- Joining the Fight
(30970, 0, 1, 0, 0, 'The Sha of Hatred\'s passing did this to them. I doubt this is the only thing that will have been affected by its passing.', 27377), -- Enraged By Hatred
(30971, 1, 1, 0, 0, 'The pandaren at the bridge are depending on us...', 27377), -- Taking Stock
(30898, 0, 1, 0, 0, 'I can\'t remember the last time they swarmed this thickly. They probably haven\'t within my lifetime.', 27377), -- Cutting the Swarm
(30896, 0, 1, 0, 0, 'I haven\'t hated plants so much since my job back at Halfhill.', 27377), -- Thieves and Troublemakers
(30897, 1, 1, 0, 0, 'My mom warned me this was going to happen...', 27377), -- In the Wrong Hands
(30895, 1, 1, 0, 0, 'Back even more quickly than expected. Did you bring the seeds?', 27377), -- Improvised Ammunition
(30894, 1, 1, 0, 0, 'I\'m hoping to find a permanent counter to the mantid poison so that the men won\'t be afflicted in the first place. It may take some time to piece it together.', 27377), -- Rummaging Through the Remains
(30892, 0, 1, 0, 0, 'With the constant mantid attacks, the men are being worked to the bone. We are undermanned on all fronts.$B$BYour help means a lot to us, $n.', 27377), -- Back on Their Feet
(30893, 0, 1, 0, 0, 'Our vigil is never-ending.', 27377), -- The Endless Swarm
(30890, 0, 1, 0, 0, 'This whole battlefront is being worked to the bone. We need more men out here.', 27377), -- The Restless Watch
(30888, 0, 1, 0, 0, 'The defenders on the wall are stretched thin. The Yaungol are pushing through the gates to Kun-Lai in the north. The mantid are pouring against the gates to the Vale of Eternal Blossoms. I hear that there\'s been a breach into the Valley of Four Winds in the south too.$B$BWe do not have the men to combat all of these threats.', 27377), -- Breach in the Defenses
(30889, 0, 1, 0, 0, 'These traps have been very effective, the mantid numbers are just getting out of hand in these past weeks.', 27377), -- Trap Setting
(30891, 1, 1, 0, 0, 'Mixed properly, the pollen from these flowers can eat away at the poison without doing any lasting damage to the body otherwise.', 27377), -- Treatment for the Troops
(30792, 0, 0, 0, 0, 'I require more mist. I am fading...', 27377), -- Orbiss Fades
(30791, 0, 0, 0, 0, 'Our preparation will not take much longer.', 27377), -- Arconiss Thirsts
(30790, 0, 0, 0, 0, 'Golgoss\' hunger is great.', 27377), -- Golgoss Hungers
(30789, 0, 0, 0, 0, 'Arconiss\' size belies his prowess in battle. He will be an asset.', 27377), -- Arconiss
(30788, 0, 0, 0, 0, 'Golgoss is no coward. He will relish the opportunity for revenge.', 27377), -- Golgoss
(30787, 0, 0, 0, 0, 'I can use these torches in my revenge.$b$bI have not succumbed to this wound yet. I can still have my revenge before I die.$b$bThere is time yet.', 27377), -- The Torches
(30786, 0, 0, 0, 0, 'I will not die before having my revenge.', 27377), -- A Spear Through My Side, A Chain Through My Soul
(30784, 0, 0, 0, 0, 'If I could change the past, I would. If I could take Lin\'s place, I would.$B$BIn a thousand lifetimes, I will never be able to repay Suna\'s loss, or share even a measure of her grief.', 27377), -- The Point of No Return
(30783, 0, 0, 0, 0, 'Our people are possessed by hatred. We must help them come to their senses!', 27377), -- Hatred Becomes Us
(30780, 0, 0, 0, 0, 'I do believe the totems could be of use to us.', 27377), -- Totemic Research
(30779, 0, 0, 0, 0, 'It is better to be safe than sorry.', 27377), -- Slaying the Scavengers
(30778, 0, 0, 0, 0, 'The stench of death is overpowering.', 27377), -- Dust to Dust
(30776, 0, 0, 0, 0, 'Jung Duk\'s legacy is written in the blood of innocents.', 27377), -- Jung Duk
(30775, 0, 0, 0, 0, 'How could they have betrayed me? They were once my brothers!$B$BWhy did they turn on me? WHY?$B$BI hate them! I will slaughter them all!', 27377), -- The Exile
(30774, 0, 0, 0, 0, 'How did it go?', 27377), -- Ranger Rescue
(30773, 0, 0, 0, 0, 'Fire is a cruel weapon. Luckily, we are only using it to destroy weapons of war.', 27377), -- Pitching In
(30772, 0, 0, 0, 0, 'I like to attack problems head on.', 27377), -- Seeing Red
(30771, 0, 0, 0, 0, 'The yaungol are not content merely to defeat their enemies. No, they would rather destroy and decimate them.', 0), -- Perfect Pitch
(30814, 0, 0, 0, 0, 'We are slowly gaining ground.', 27377), -- A Foot in the Door
(31394, 0, 0, 0, 0, 'Are you finished with the White Tiger\'s tasks?', 27377), -- A Celestial Experience
(30820, 0, 0, 0, 0, 'You must light the incense to honor the dead.', 27377), -- A Funeral
(30806, 0, 0, 0, 0, 'Are those the ingredients for Incense of Life I smell on you? Or... perhaps you haven\'t bathed recently.', 27377), -- The Scent of Life
(30807, 0, 0, 0, 0, 'The stones - have you brought them?', 27377), -- By the Falls, For the Fallen
(30805, 0, 0, 0, 0, 'Are they dead? Have you dealt with them?', 27377), -- Justice
(31228, 0, 0, 0, 0, 'Is Khar\'zul dead?', 27377), -- Prophet Khar'zul
(30946, 0, 1, 0, 0, 'What did the prisoner have to say?', 27377), -- Revelations
(31011, 0, 1, 0, 0, 'The village must be saved!', 27377), -- Enemies At Our Door
(30943, 1, 1, 0, 0, 'Were you able to find a suitable amount of volatile blooms?', 27377), -- Handle With Care
(30942, 0, 1, 0, 0, 'I\'ll show my father he\'s wrong about me!', 27377), -- Make A Fighter Out of Me
(30945, 0, 0, 0, 0, 'We\'ll need more than luck to get us through this. I hope you found something I can work with.', 27377), -- What's Yours Is Mine
(30944, 0, 1, 0, 0, 'Are the villagers recovering?', 27377), -- It Takes A Village
(30802, 0, 0, 0, 0, 'Were you able to find any information on their location?', 27377), -- Chasing the Storm
(30801, 0, 0, 0, 0, 'Have you read the tablet?', 27377), -- Lessons from History
(30800, 0, 0, 0, 0, 'Have you figured out where the Thunder King\'s remains are hidden?', 27377), -- Stealing Their Thunder King
(30798, 0, 0, 0, 0, 'Have you gone to the Tomb of Secrets yet?', 27377), -- Breaking the Emperor's Shield
(30799, 0, 0, 0, 0, 'Did you find anything in the Tomb of Shadows?', 27377), -- The Tomb of Shadows
(30797, 0, 0, 0, 0, 'What have you found, $n?', 0), -- It Was Almost Alive
(30796, 0, 0, 0, 0, 'Have you disposed of the spirits yet?', 27377), -- An End to Everything
(30829, 0, 0, 0, 0, 'I\'ll need to bind my essence to the Tongue, then you can use it to speak with me from anywhere.', 27377), -- The Tongue of Ba-Shon
(30993, 0, 0, 0, 0, 'Here we are, then.', 27377), -- Where are My Reinforcements?
(30991, 0, 0, 0, 0, 'Wha? I was just thinking about my poor, poor beer...', 27377), -- Do a Barrel Roll!
(30751, 0, 0, 0, 0, 'Do you have the oil?', 27377), -- A Terrible Sacrifice
(30750, 0, 0, 0, 0, 'Come on, come on.', 27377), -- Off the Wall!
(30715, 0, 0, 0, 0, 'Our comrades, are they at rest?', 27377), -- A Line Unbroken
(30723, 0, 5, 0, 0, 'Killing those birds may not soothe my anger, but at least it proves that we are better than our enemies. They would not do such a thing.', 27377), -- Honor, Even in Death
(30690, 0, 396, 0, 0, 'Is Malevolent Fury gone?', 27377), -- Unmasking the Yaungol
(30665, 0, 0, 0, 0, 'Have you dealt with the yaungol yet?', 27377), -- The Defense of Shado-Pan Fallback
(30670, 0, 0, 0, 0, 'Have you harvested their essences?', 27377), -- Turnabout
(30747, 0, 0, 0, 0, 'Don\'t push our luck... we promised her hozens-smashies.', 27377), -- The Burlap Grind
(30746, 0, 0, 0, 0, 'Kota Kon wants more kafa, but I already fed her all I have! Then I tried giving her a nice bow, but she\'s not satisfied!$B$B<The terrified grummle gulps and leans in close to whisper.>$B$BI think she can smell the kafa I drank for breakfast...', 0), -- A Fair Trade
(30744, 0, 0, 0, 0, '<This should be more than enough berries to satisfy Uncle Keenbean.>', 0), -- Kota Blend
(30743, 0, 0, 0, 0, 'On the bright side, Uncle Keenbean can label the last batch of Kafa\'goot as \"Limited Release\" and sell it for even more!', 27377), -- Gourmet Kafa
(30742, 0, 0, 0, 0, 'I shoulda never fed them goots.', 27377), -- Shut it Down
(30745, 0, 0, 0, 0, 'Don\'t wanna fight yetis? Can\'t say I blame you.', 27377), -- Trouble Brewing
(30611, 0, 0, 0, 0, 'We found a yak. Did you take out some hozen?', 27377), -- Unleash The Yeti!
(30610, 0, 0, 0, 0, 'Grummles are good at carrying things.', 27377), -- Grummle! Grummle! Grummle!
(30608, 0, 0, 0, 0, 'Other grummles say I not have good luck. The call me \"Luckydon\'t\".$b$bBut now I have friend $r who is a big luckydo! We\'ll show them.', 27377), -- The Snackrifice
(30607, 0, 0, 0, 0, 'A luckydo would be wise to never travel near a yeti on a dirty yak.', 27377), -- Hozen Love Their Keys
(30604, 0, 0, 0, 0, 'This is not vengeance or fortune, it is survival.', 27377), -- Breaking Broketooth
(30600, 0, 0, 0, 0, 'Grummles are a simple people. We are made to explore and deliver.', 27377), -- No Pack Left Behind
(30599, 0, 0, 0, 0, 'Hozen are learning that it is most bad fortune to get sacrificed on one\'s own altar.', 27377), -- A Monkey Idol
(30603, 0, 0, 0, 0, 'Grummles named for the luckydo that gives the most fortune to specific grummle. It is most important that hozen not steal a grummle\'s luck.', 0), -- The Broketooth Ravage
(30683, 0, 396, 0, 0, 'Nephew Bentnail has already eaten two days worth of food. I hope you found us more!', 27377), -- One Traveler's Misfortune
(30618, 0, 0, 0, 0, 'Did you manage to get some of my supplies back?', 27377), -- Resupplying One Keg
(30621, 0, 0, 0, 0, 'Were you able to find my lucky trinkets? One can never have too much good luck.', 27377), -- They Stole My Luck!
(30601, 0, 1, 0, 0, 'Did you find the hiding guides?', 27377), -- Instant Courage
(30808, 0, 0, 0, 0, 'A luckydo is a thing of much good fortune. Yaungol know nothing of how to use luckydos... yet.', 27377), -- A Grummle's Luck
(30614, 0, 0, 0, 0, 'Yaungols are scary. Yaungols with a luckydo like this \"oil\" are more scary.', 27377), -- Oil Stop
(30616, 0, 0, 0, 0, 'A luckydon\'t travels a trail during a yaungol raid. A luckydo hires a big fighter type to help.', 27377), -- Traffic Issues
(30804, 0, 0, 0, 0, 'So many strangers in these lands these days. Luckily you $c seem to be all right.', 27377), -- The Fearmaster
(30582, 0, 0, 0, 0, 'Oh, and what have you there.', 0), -- The Late Mrs. Muskpaw
(30491, 0, 0, 0, 0, 'The grummles always insist they have better luck with cleaned yaks.$b$bAs long as they pay more I\'m not going to argue. We need the gold. Now more than ever.', 27377), -- At the Yak Wash
(30489, 0, 0, 0, 0, 'Mmm. Nothing like the fresh scent of needle.', 27377), -- Fresh Needle Scent
(30651, 0, 6, 0, 0, 'I\'m a wee bit surprised by the lack o\' explosions I\'ve seen so far.$B$BAre you well?', 27377), -- Barrels of Fun
(30581, 6, 6, 0, 0, 'Do you have everything from the list?!', 27377), -- ... and the Pot, Too!
(30571, 0, 6, 0, 0, 'Look, $g mister : lady;, I don\'t mean to be telling you your business, but I can still see a lot of my farmhands still out there.', 27377), -- Farmhand Freedom
(30595, 6, 6, 0, 0, 'Where am I going to be able to put all of the relics?', 27377), -- Profiting off of the Past
(30593, 0, 6, 0, 0, 'Please tell me that you have the Mogujia situation under control. Please?', 27377), -- Deanimate the Reanimated
(30619, 0, 6, 0, 0, 'Did you find him? Is he dead? No? Oh, man. Don\'t make me worried!', 27377), -- Mogu?! Oh No-gu!
(30583, 6, 6, 0, 0, 'Well... ya\' got my meat?', 27377), -- Blue Dwarf Needs Food Badly
(30575, 0, 274, 0, 0, 'It\'s going to take more yaks than that to get this place back into fightin\' condition, $n, yes it is.', 27377), -- Round 'Em Up
(30514, 0, 0, 0, 0, 'As long as Ur-Bataar lives, we cannot have peace.', 27377), -- Challenge Accepted
(30512, 0, 0, 0, 0, 'I will not rest until our people are returned and this village rebuilt.', 27377), -- Westwind Rest
(30480, 0, 6, 0, 0, 'That... was not what I expected.', 27377), -- The Ritual
(30967, 0, 0, 0, 0, 'If we can rescue the dissenters, perhaps we can rebuild somewhere else...', 27377), -- Free the Dissenters
(30496, 396, 396, 0, 0, 'Have you found the staff?', 27377), -- The Waterspeaker's Staff
(30468, 0, 396, 0, 0, 'Are they dead?', 27377), -- Enraged Vengeance
(30469, 0, 0, 0, 0, 'Have you found the supplies?', 27377), -- Repossession
(30459, 6, 6, 0, 0, 'How many arrows do you have?', 27377), -- All of the Arrows
(30460, 0, 1, 0, 0, 'There are yet more injured warriors in need of aid, $c.', 27377), -- Hit Medicine
(30457, 0, 1, 0, 0, 'If the war leader of the yaungol is slain, surely our village will be saved and the refugees will be able to return to their farms.', 27377), -- Call Out Their Leader
(31254, 0, 0, 0, 0, 'More strangers? This day is testing my limits.', 0), -- The Road to Kun-Lai
(31611, 0, 0, 0, 0, 'Ah, still alive I see...', 27377); -- The Kun-Lai Kicker

DELETE FROM `quest_request_items` WHERE `ID` IN (34925 /*Polishing the Iron Throne*/, 34958 /*The Shadow of the Worldbreaker*/, 34987 /*The Gunpowder Plot*/, 35019 /*Prepare for Battle*/, 34393 /*The Portal's Power*/, 35933 /*Azeroth's Last Stand*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(34925, 0, 0, 0, 0, 'You\'ll have to pry that key out of his cold, ugly hand.', 27404), -- Polishing the Iron Throne
(34958, 0, 0, 0, 0, 'Any luck?', 27404), -- The Shadow of the Worldbreaker
(34987, 0, 0, 0, 0, 'Don\'t go doin\' anything inappropriate with that gunpowder, now.', 27404), -- The Gunpowder Plot
(35019, 0, 0, 0, 0, 'These prisoners are no less brave than you or I, $n. Give them a weapon and an ounce of hope and they will fight like the storm.', 27404), -- Prepare for Battle
(34393, 0, 0, 0, 0, 'Go now, hero! Lives hang in the balance!', 27404), -- The Portal's Power
(35933, 0, 0, 0, 0, 'This missive bears the mark of the Warsong clan.', 0); -- Azeroth's Last Stand

DELETE FROM `quest_request_items` WHERE `ID` IN (35015 /*Gestating Genesaur*/, 34994 /*Forever Young*/, 34995 /*Botani Beatdown*/, 35006 /*Poison Paralysis*/, 33788 /*Cooking With Unstable Herbs*/, 34996 /*Rotting Riverbeasts*/, 33808 /*Swamplighter Queen*/, 33787 /*Fiona's Solution*/, 33836 /*Wanted: Maa'run's Hoof*/, 36269 /*Hexcloth*/, 33461 /*Gloomshade Game Hunter*/, 33082 /*Ancestor's Memory*/, 37289 /*Shadowmoon Invasion!*/, 36315 /*Oru'kai's Staff*/, 36310 /*The Arakkoan Enchanter*/, 33059 /*The Fate of Karabor*/, 33078 /*The Dark that Blinds Us*/, 33076 /*The Clarity Elixir*/, 33077 /*A Grandmother's Remedy*/, 34876 /*Loola's Lost Love*/, 36643 /*Your First Tailoring Work Order*/, 36645 /*Your First Enchanting Work Order*/, 34836 /*Lunarblossom*/, 34847 /*Forbidden Love*/, 36189 /*Easing into Lumberjacking*/, 34788 /*Friend of the Exarchs*/, 34789 /*Speaker for the Dead*/, 34790 /*The Sting*/, 34784 /*Fun with Fungus*/, 34786 /*Engorged Goren*/, 35070 /*Shut 'er Down*/, 34781 /*Defenstrations*/, 36266 /*The Clothes on Their Backs*/, 36262 /*Ameeka, Master Tailor*/, 34779 /*Circle the Wagon*/, 36202 /*Anglin' In Our Garrison*/, 36201 /*Proving Your Worth*/, 36199 /*Moonshell Claws*/, 37433 /*Proving Grounds*/, 36615 /*My Very Own Castle*/, 34192 /*Things Are Not Goren Our Way*/, 36404 /*Clearing the Garden*/, 34019 /*Shadows Awaken*/, 33813 /*In Need of a Hero*/, 33833 /*Wanted: Kuu'rat's Tusks*/, 33834 /*Wanted: Kliaa's Stinger*/, 33114 /*Forging the Soul Trap*/, 33168 /*Heart On Fire*/, 33066 /*Soul Shards of Summoning*/, 36592 /*Bigger is Better*/, 34692 /*Delegating on Draenor*/, 36236 /*The Cryptic Tome of Tailoring*/, 33269 /*Cleaning Up Gul'var*/, 33112 /*Ominous Portents*/, 33419 /*A Matter of Life and Death*/, 33115 /*Shrouding Stones*/, 33120 /*A Curse Upon the Woods*/, 33113 /*Shadowmoonwell*/, 33062 /*Catching His Eye*/, 35174 /*Pale Moonlight*/, 35166 /*Ship Salvage*/, 35176 /*Keeping it Together*/, 34585 /*Quakefist*/, 34616 /*Ravenous Ravens*/, 34584 /*Looking for Lumber*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(35015, 0, 0, 0, 0, 'I never thought I would see a genesaur in my lifetime.', 27547), -- Gestating Genesaur
(34994, 0, 0, 0, 0, 'Did you find any Youngroot?', 27547), -- Forever Young
(34995, 0, 0, 0, 0, 'How many did you kill?', 27547), -- Botani Beatdown
(35006, 0, 0, 0, 0, 'Did you find the others?', 27547), -- Poison Paralysis
(33788, 0, 396, 0, 0, 'Are you ready to begin?', 27547), -- Cooking With Unstable Herbs
(34996, 0, 0, 0, 0, 'We need to stop this infestation.', 27547), -- Rotting Riverbeasts
(33808, 396, 396, 0, 0, 'I just wanted to pick some herbs and relax with my boys... I should have stayed in Azeroth.', 27547), -- Swamplighter Queen
(33787, 396, 396, 0, 0, 'Do you have the ingredients?', 27547), -- Fiona's Solution
(33836, 0, 0, 0, 0, 'My brother, Anduur, gathers wild berries from the hills above our village.$B$BIt was during one of his excursions that he met up with Maa\'run.$B$BI demand retribution for his injuries.', 27547), -- Wanted: Maa'run's Hoof
(36269, 0, 0, 0, 0, 'Were you successful, friend?', 27547), -- Hexcloth
(33461, 0, 0, 0, 0, 'Did you find all the ingredients I need?', 0), -- Gloomshade Game Hunter
(33082, 0, 0, 0, 0, 'You must understand a man\'s life before taking it.', 27547), -- Ancestor's Memory
(37289, 0, 0, 0, 0, 'Time to shine a light on these shadows!', 27547), -- Shadowmoon Invasion!
(36315, 0, 0, 0, 0, 'The staff! Give it to me!', 0), -- Oru'kai's Staff
(36310, 0, 0, 0, 0, 'Greetings Enchanter. I can see you are acquainted with the art. \n\nGood, good. Perhaps you and I can help each other.', 0), -- The Arakkoan Enchanter
(33059, 0, 0, 0, 0, '<The Prophet is deep in thought. He looks troubled.>', 27547), -- The Fate of Karabor
(33078, 0, 0, 0, 0, 'What did you find?', 27547), -- The Dark that Blinds Us
(33076, 572, 572, 500, 500, 'Yes?', 27547), -- The Clarity Elixir
(33077, 0, 0, 0, 0, 'It\'s all downhill from here, dearie.', 27547), -- A Grandmother's Remedy
(34876, 0, 0, 0, 0, 'Knowing my husband he\'s probably hibernating. Did you check the loose mud in the marsh?', 27547), -- Loola's Lost Love
(36643, 0, 0, 0, 0, 'Yes?', 0), -- Your First Tailoring Work Order
(36645, 0, 0, 0, 0, 'Yes?', 0), -- Your First Enchanting Work Order
(34836, 0, 0, 0, 0, 'How can I help you, $c?', 27547), -- Lunarblossom
(34847, 0, 0, 0, 0, 'My son needs to learn to respect his elders.', 27547), -- Forbidden Love
(36189, 547, 547, 0, 0, 'This garrison isn\'t going to build itself, commander! We need timber!', 27547), -- Easing into Lumberjacking
(34788, 0, 0, 0, 0, 'Who are you going to pick, $n?', 27547), -- Friend of the Exarchs
(34789, 0, 274, 0, 0, 'Exarch Hataaru didn\'t deserve to die that way. Not like this.', 27547), -- Speaker for the Dead
(34790, 6, 6, 0, 0, 'Most draenei avoid the Umbrafen, but we rangari seem drawn to the most dangerous places - that\'s where you really learn how the world works.', 27547), -- The Sting
(34784, 0, 0, 0, 0, 'Remember, unless you are covered in shimmershroom dust, the spores will explode as soon as you get near.', 27547), -- Fun with Fungus
(34786, 6, 6, 0, 0, 'What\'s the status inside the dig?', 27547), -- Engorged Goren
(35070, 0, 6, 0, 0, 'Have you braved the mines yet, $c?', 27547), -- Shut 'er Down
(34781, 0, 0, 0, 0, 'The sounds of attack still reverberate from outside, which is alarming, given that the console seems awash with angrily blinking warning indicators.', 27547), -- Defenstrations
(36266, 0, 0, 0, 0, 'Were you able to get the robes?', 27547), -- The Clothes on Their Backs
(36262, 0, 0, 0, 0, 'Hello, traveler! Is there something that I can help you with?', 0), -- Ameeka, Master Tailor
(34779, 0, 0, 0, 0, 'Did you find them? Check the woods to the northwest. If I know Maraad, he probably tried to take the shelter of a hill.', 27547), -- Circle the Wagon
(36202, 6, 0, 0, 0, 'We can use that as bait?!', 0), -- Anglin' In Our Garrison
(36201, 6, 6, 0, 0, 'Catch those sturgeon?', 27547), -- Proving Your Worth
(36199, 6, 6, 0, 0, 'Have those claws for me?', 27547), -- Moonshell Claws
(37433, 0, 0, 0, 0, 'Have you completed your challenge?', 27547), -- Proving Grounds
(36615, 0, 5, 0, 0, 'I\'m giddy with excitement!', 27547), -- My Very Own Castle
(34192, 0, 6, 0, 0, 'Were you able to take out the leader?', 27547), -- Things Are Not Goren Our Way
(36404, 0, 6, 0, 0, 'Did you get \'em?', 27547), -- Clearing the Garden
(34019, 0, 0, 0, 0, 'The Shadowmoon clan\'s aggression began when the Iron Horde arrived on Draenor.', 27547), -- Shadows Awaken
(33813, 0, 0, 0, 0, 'Squiggy... is... my... best... friend!', 27547), -- In Need of a Hero
(33833, 0, 0, 0, 0, 'Are you here for the bounty on Kuu\'rat?', 0), -- Wanted: Kuu'rat's Tusks
(33834, 0, 0, 0, 0, 'Word around town is you\'ve been hunting Kliaa. Any luck?', 0), -- Wanted: Kliaa's Stinger
(33114, 1, 1, 0, 0, 'With the soul shards combined, we will trap Gul\'dan and put an end to the Shadow Council on Draenor.', 27547), -- Forging the Soul Trap
(33168, 1, 1, 0, 0, 'With the combined might of the shards, we should be able to trap Gul\'dan.', 27547), -- Heart On Fire
(33066, 6, 0, 0, 0, 'Do you have the shards, $n?', 0), -- Soul Shards of Summoning
(36592, 0, 6, 0, 0, 'What do you think? Time for an upgrade?', 27547), -- Bigger is Better
(34692, 0, 0, 0, 0, 'You can use the Command Table to assign missions to your followers.', 27547), -- Delegating on Draenor
(36236, 0, 0, 0, 0, 'What have you there, child?', 0), -- The Cryptic Tome of Tailoring
(33269, 0, 1, 0, 0, 'We need to nip the Shadow Council in the bud while their numbers are still low on this world.', 27547), -- Cleaning Up Gul'var
(33112, 0, 0, 0, 0, 'The demon must be put to the test if we\'re to find out what\'s happening at Gul\'var.', 27547), -- Ominous Portents
(33419, 0, 0, 0, 0, 'They told us not to come out here, but we didn\'t listen. Why didn\'t we listen!?', 27547), -- A Matter of Life and Death
(33115, 0, 5, 0, 0, 'Once the shrouding stones are destroyed, we\'ll turn our attention to breaking this demon\'s will.', 27547), -- Shrouding Stones
(33120, 0, 1, 0, 0, 'I know it may seem harsh, and I\'ll understand if you decide not to do it.$B$BHowever, the sooner you kill those poor creatures, the sooner their suffering will come to an end.', 27547), -- A Curse Upon the Woods
(33113, 396, 396, 0, 0, 'With that chunk of fallen rock, I\'ll be able to complete the dedication of the moonwell.', 27547), -- Shadowmoonwell
(33062, 0, 396, 0, 0, 'We\'re going to capture the All-Seeing Eye and break its will.$B$BThis is the way that we\'ll be able to scry upon the Shadow Council at Gul\'var without them knowing it\'s us.', 27547), -- Catching His Eye
(35174, 0, 0, 0, 0, 'Did you see the pale orcs, commander?', 27547), -- Pale Moonlight
(35166, 0, 0, 0, 0, 'Supplies are getting really low, commander.', 27547), -- Ship Salvage
(35176, 0, 0, 0, 0, 'Can we speak a little later, $GSir:Madam;? I don\'t really have time to talk at the moment.', 27547), -- Keeping it Together
(34585, 0, 0, 0, 0, 'Did you kill the giant in the cave?', 27547), -- Quakefist
(34616, 0, 0, 0, 0, 'Did you kill those ravens?', 27547), -- Ravenous Ravens
(34584, 0, 0, 0, 0, 'How goes the lumber hunt?', 27547); -- Looking for Lumber

DELETE FROM `quest_request_items` WHERE `ID` IN (39666 /*Equipping Our Fleet*/, 39655 /*If At First You Fail, Try Again!*/, 39404 /*Destroying the Competition*/, 39056 /*Naval Commander*/, 34027 /*Groundbreaking Data*/, 39581 /*Demonslayer of Tanaan*/, 39432 /*Unknowable Power*/, 39313 /*Bring the Reinforcements*/, 38603 /*Setting the Signal*/, 36686 /*Assault on the Pit*/, 35395 /*The Fate of Gordawg*/, 37210 /*Aogexon's Fang*/, 36222 /*The Champion of Blood*/, 36221 /*Entry Fee*/, 36220 /*How Tough Are You?*/, 35140 /*THAELIN!*/, 35069 /*Terror of Nagrand*/, 35386 /*The Warsong Threat*/, 35023 /*Echoes of the Past*/, 35022 /*Lighting The Darkness*/, 35088 /*The Shadow of the Void*/, 35086 /*The Void March*/, 35087 /*The Nether Approaches*/, 35085 /*Through the Nether*/, 35083 /*Disrupt the Rituals*/, 35084 /*Silence the Call*/, 35330 /*The Ritual of Binding*/, 34932 /*Guise of the Deceiver*/, 34894 /*A Rare Bloom*/, 34893 /*Guardians of the Plateau*/, 34881 /*Earth, Wind and Fire...and Water*/, 35333 /*Elemental Attunement*/, 35331 /*Called to the Throne*/, 36285 /*Dirgemire*/, 36284 /*A Fascinating Fungus*/, 36275 /*The Search For Research*/, 37318 /*The Dead Do Not Forget...*/, 34955 /*Not Without My Honor*/, 34954 /*The Blade Itself*/, 34593 /*Obtaining Ogre Offensive Orders*/, 35632 /*A Lesson in Archaeology*/, 35663 /*A Lesson in Teamwork*/, 34809 /*A Lesson in Mineralogy*/, 34666 /*Ring of Trials: Roakk the Zealot*/, 34665 /*Ring of Trials: Captain Boomspark*/, 34664 /*Ring of Trials: Hol'yelaa*/, 34514 /*They've Got The Goods!*/, 34900 /*New Babies*/, 34819 /*Fruitful Ventures*/, 34811 /*Good Help is Hard to Find*/, 35350 /*Queen of the Clefthoof*/, 35357 /*King of the Breezestriders*/, 36273 /*Whacking Weeds*/, 34512 /*Declawing The Competition*/, 34662 /*Ring of Trials: Crushmaul*/, 34869 /*Tastes Like Chicken*/, 35928 /*Meatgut Needs Bones*/, 35338 /*Shooting the Breeze*/, 35337 /*That Pounding Sound*/, 34952 /*The Friend o' My Enemy*/, 34769 /*A Choice to Make*/, 34746 /*Shields Down!*/, 34719 /*... and My Hammer*/, 34718 /*The Others*/, 34678 /*Up and Running*/, 36385 /*Legacy of the Ancients*/, 34448 /*Kaelynara Sunchaser*/, 34415 /*An'dure The Giant*/, 34406 /*Caught In The Chaos*/, 34403 /*Arcane Essence*/, 34400 /*Frenzied Manafeeders*/, 33944 /*And the Elekk Too?!*/, 33884 /*Sher'KHAAAAAAANNNN!*/, 33882 /*Just Peachicky*/, 34164 /*Book Burning*/, 35254 /*Retribution for the Light*/, 35227 /*Ogre Diplomacy*/, 34092 /*Desperate Measures*/, 33976 /*The Final Piece*/, 33988 /*Invasion of the Soul Eaters*/, 34013 /*Never Forget*/, 34234 /*Payback*/, 33969 /*Vile Defilers*/, 33967 /*Antivenin*/, 33958 /*Into the Hollow*/, 34351 /*We Must Construct Additional Pylons*/, 34407 /*Holding the Line*/, 33920 /*The Heart of Auchindoun*/, 34978 /*Prized Repossessions*/, 34979 /*Punching Through*/, 34977 /*Supply Recovery*/, 34777 /*Gatekeepers of Auchindoun*/, 34802 /*A Pilgrimage Gone Awry*/, 33874 /*Aruumel's Rest*/, 33761 /*Barum's Notes*/, 33734 /*Pieces of Us*/, 34761 /*Clear!*/, 33872 /*Dust of the Dead*/, 33873 /*Cure of Aruunem*/, 33581 /*Forbidden Knowledge*/, 33582 /*Kura's Vengeance*/, 33580 /*The Purge of Veil Shadar*/, 34465 /*Mysterious Hat*/, 34463 /*Mysterious Ring*/, 34097 /*Born to Shred*/, 34096 /*An Eye for a Spy*/, 33973 /*Dying Wish*/, 34095 /*Iron Them Out*/, 34959 /*Dreadpiston*/, 34094 /*Vol. X Pages ?*/, 34090 /*Thaelin's Quick Fix*/, 34088 /*Too Many Irons in the Fire*/, 34089 /*In Short Supply*/, 34087 /*Through the Looking Glass*/, 34804 /*Not In Your House*/, 34773 /*Why Is The Brew Gone?*/, 34105 /*Wanted: Ra'tok the Hammer*/, 34104 /*Wanted: Hilaani*/, 34103 /*Wanted: Kil'uun*/, 34624 /*Gas Guzzlers*/, 34573 /*Iridium Recovery*/, 34571 /*Out of Jovite*/, 34558 /*At Your Command*/, 33633 /*Rooter the Ravenous*/, 36442 /*Taking the Death Bloom*/, 36441 /*Reclaiming Property*/, 36575 /*Strike While the Iron is Hot*/, 35235 /*Iyu*/, 35234 /*Will of the Genesaur*/, 35233 /*Just In Case*/, 35229 /*Down the Goren Hole*/, 35209 /*The Life Spring*/, 35207 /*Coalpart's Revenge*/, 36523 /*A Green Ogron?*/, 35205 /*Burn the Bodies*/, 35206 /*Bushwhacker*/, 35204 /*Pollen Power*/, 35216 /*Super Seeds*/, 35214 /*The Infested*/, 35213 /*The Razorbloom*/, 35652 /*Growing Wood*/, 35647 /*A Grim Harvest*/, 35645 /*The Secret of the Fungus*/, 35644 /*Mercy for the Living*/, 35633 /*Scout Forensics*/, 35063 /*We Need An Outpost*/, 35050 /*Rescue Rangari*/, 35055 /*Lost Mole Machines*/, 37149 /*The Void-Gate*/, 37155 /*The Brass Compass*/, 39055 /*Ship Shape*/, 39054 /*Shipbuilding*/, 38259 /*All Hands on Deck*/, 38256 /*Hook, Line, and... Sink Him!*/, 38254 /*Derailment*/, 37151 /*Cold Steel*/, 37164 /*The Huntresses*/, 37087 /*Lost in Transition*/, 38354 /*Portable Portals*/, 36848 /*Ogre Waygates*/, 36316 /*Victory is Within Reach*/, 34924 /*The Egg Thieves*/, 34939 /*Declawing The Bloodmane*/, 34922 /*Words of the Raven Mother*/, 34923 /*The Bloodmane*/, 34991 /*To the... Rescue?*/, 35634 /*Control is King*/, 35261 /*Shot-Caller*/, 35260 /*Hardly Working*/, 35258 /*Legacy of the Apexis*/, 34883 /*A Feast of Shadows*/, 34882 /*Blades in the Dark*/, 34829 /*New Neighbors*/, 34828 /*Ishaal's Orb*/, 34886 /*Baby Bird*/, 34884 /*The Kaliri Whisperer*/, 35245 /*A Sentimental Relic*/, 35013 /*Lithic's Gift*/, 35011 /*The False Talon King*/, 35002 /*Sons of Sethe*/, 35000 /*Banished From the Sky*/, 34998 /*Talon Watch*/, 34999 /*Hatred Undying*/, 35675 /*Wanted: Spineslicer's Husk*/, 37287 /*Cleaning House*/, 36048 /*We Have Him Now*/, 36023 /*Extrinsic Motivation*/, 35959 /*The Power of Poison*/, 35926 /*Assassin's Mark*/, 35408 /*Prime the Cannons*/, 35407 /*Punishable by Death*/, 35353 /*A Piece of the Puzzle*/, 35339 /*A Parting Favor*/, 35329 /*I See Dead People*/, 35674 /*Wanted: Keeho's Severed Paw*/, 35286 /*Orders, Commander?*/, 35274 /*One of Our Own*/, 35668 /*Syth's Secret*/, 35636 /*All Due Respect*/, 34659 /*The Crone*/, 34658 /*Orders From On High*/, 34656 /*Hidden in Plain Sight*/, 34657 /*Adherents of the Sun God*/, 36428 /*Curing With Force*/, 35211 /*Preventing the Worst*/, 35091 /*Sporicide*/, 35089 /*Skimming Off the Top*/, 35090 /*The Right Parts for the Job*/, 36384 /*Field Trial*/, 35081 /*Clearing Out Before Cleaning Up*/, 35082 /*Getting the Crew Back Together*/, 35079 /*Spore-be-Gone*/, 35077 /*Defungination*/, 38356 /*Bringing the Bass*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(39666, 0, 0, 0, 0, 'Yes?', 27602), -- Equipping Our Fleet
(39655, 0, 0, 0, 0, 'Get that replacement Destroyer built?', 27602), -- If At First You Fail, Try Again!
(39404, 0, 0, 0, 0, 'What is the status of the Destroyer?', 27602), -- Destroying the Competition
(39056, 0, 0, 0, 0, 'Finish a naval mission yet?', 27602), -- Naval Commander
(34027, 0, 0, 0, 0, 'Go on, check out the Tremor-Tracker! It ain\'t gonna bite ye.', 27602), -- Groundbreaking Data
(39581, 0, 6, 0, 0, '<Parvink looks at some hatch marks she scribbled on a scrap of paper.>$b$bI\'m up to 17 demons killed today. You?', 27602), -- Demonslayer of Tanaan
(39432, 0, 0, 0, 0, 'This is simply the beginning of what you must do to save what remains of the Arakkoa.', 27602), -- Unknowable Power
(39313, 0, 0, 0, 0, 'Which allies should I call for?', 27602), -- Bring the Reinforcements
(38603, 0, 0, 0, 0, 'Do you have those sensors in position?', 27602), -- Setting the Signal
(36686, 0, 6, 0, 0, 'How goes the assault, $gsir:ma\'am;?', 27602), -- Assault on the Pit
(35395, 1, 0, 0, 0, 'What of Gordawg? Has the great fury been brought to rest?', 0), -- The Fate of Gordawg
(37210, 0, 0, 0, 0, 'Aogexon is one of the most feared beasts in Nagrand, and one of the largest and most dangerous forest stalkers ever seen!$b$bI\'ve already been approached by a number of a collectors interested in obtaining one of Aogexon\'s deadly fangs. If you are up for the challenge, Aogexon can sometimes be found lurking in the swamp not far from here.$b$bGood luck!', 0), -- Aogexon's Fang
(36222, 0, 0, 0, 0, 'Only da very best be havin\' a chance at bein\' da Blood Champion, mon.', 27602), -- The Champion of Blood
(36221, 6, 0, 0, 0, 'Don\'t be wastin\' my time, $r. What business do you be havin\' with Mogor?', 0), -- Entry Fee
(36220, 0, 0, 0, 0, 'Nobody gets in da proving grounds unless I say so.', 27602), -- How Tough Are You?
(35140, 0, 6, 0, 0, 'Did you round them all up?', 27602), -- THAELIN!
(35069, 6, 0, 0, 0, 'Commander. How may I help you?', 0), -- Terror of Nagrand
(35386, 1, 0, 0, 0, 'What do you have for me?', 0), -- The Warsong Threat
(35023, 0, 1, 0, 0, 'Have you disposed of the tormented echoes that walk the Ancestral Grounds?', 27602), -- Echoes of the Past
(35022, 0, 1, 0, 0, 'Have you placed the spirit flame upon the pyres, $n?', 27602), -- Lighting The Darkness
(35088, 0, 1, 0, 0, 'Have you defeated Invalidus?', 27602), -- The Shadow of the Void
(35086, 0, 1, 0, 0, 'If the void creatures are not dealt with, Invalidus will grow too powerful to stop.', 27602), -- The Void March
(35087, 0, 1, 0, 0, 'Should the portals open and connect the Twisting Nether to Draenor, the path will be clear for the armies of the void to march upon our world!', 27602), -- The Nether Approaches
(35085, 0, 1, 0, 0, 'The veil between dimensions is thin. Do you hear my words through the shaman stone?', 27602), -- Through the Nether
(35083, 0, 1, 0, 0, 'Have you destroyed the ritual totems?', 27602), -- Disrupt the Rituals
(35084, 0, 1, 0, 0, 'Have you put an end to the Warsong ritualists?', 27602), -- Silence the Call
(35330, 0, 1, 0, 0, 'Speak to me of your vision, $n. What mysteries did you behold?', 27602), -- The Ritual of Binding
(34932, 0, 1, 0, 0, 'I have not much time left. Please, discover the truth of Dahaka\'s death before it is too late.', 27602), -- Guise of the Deceiver
(34894, 1, 1, 0, 0, 'Do you have the Ember Blossom?', 27602), -- A Rare Bloom
(34893, 0, 1, 0, 0, 'Have you cleansed the plateau of the corrupted guardians?', 27602), -- Guardians of the Plateau
(34881, 1, 1, 0, 0, 'Bring to me the living essences of the elements, that I may plant the seeds of rebirth.', 27602), -- Earth, Wind and Fire...and Water
(35333, 0, 1, 0, 0, 'Have you attuned with the elemental pillars upon the Elemental Plateau?', 27602), -- Elemental Attunement
(35331, 0, 1, 0, 0, 'Are you ready to commune with the elemental spirits of the throne?', 27602), -- Called to the Throne
(36285, 1, 1, 0, 0, 'Without a fungal brain to examine, the mysteries of the Zangar ecosystem will remain unsolved!', 27602), -- Dirgemire
(36284, 1, 1, 0, 0, 'Have you collected the spore samples for my research?', 27602), -- A Fascinating Fungus
(36275, 1, 1, 0, 0, 'Have you retrieved my missing belongings?', 27602), -- The Search For Research
(37318, 0, 0, 0, 0, '<The cauldron bubbles and boils.>', 27602), -- The Dead Do Not Forget...
(34955, 6, 6, 0, 0, 'Do you have my banner?', 27602), -- Not Without My Honor
(34954, 274, 274, 0, 0, 'A blademaster without a blade is no blademaster at all.', 27602), -- The Blade Itself
(34593, 0, 0, 0, 0, 'Those orders would be really useful in piecing this whole thing together.', 0), -- Obtaining Ogre Offensive Orders
(35632, 0, 1, 0, 0, 'Have you found the Highmaul relic yet?', 27602), -- A Lesson in Archaeology
(35663, 1, 1, 0, 0, 'Have you retrieved the mysterious artifacts? It\'s all about teamwork!', 27602), -- A Lesson in Teamwork
(34809, 0, 0, 0, 0, '<The Gold-O-Matic 9000 buzzes and whirrs with the sounds of heavy machinery.>', 0), -- A Lesson in Mineralogy
(34666, 0, 1, 0, 0, 'What are you doing standing around? Don\'t you hear the crowd screaming?$b$bThere\'s a championship waiting on you!', 27602), -- Ring of Trials: Roakk the Zealot
(34665, 0, 1, 0, 0, 'What are you doing standing around? Get in the arena and spill some blood!', 27602), -- Ring of Trials: Captain Boomspark
(34664, 0, 1, 0, 0, 'What are you doing standing around? Get in the arena and spill some blood!', 27602), -- Ring of Trials: Hol'yelaa
(34514, 0, 0, 0, 0, 'Greexlex told you that the saberon stole our merchandise?$b$bWell, what are you standing around for? Get your butt over to Sabermaw and get it back!$b$bTime is money!', 0), -- They've Got The Goods!
(34900, 0, 273, 0, 0, 'Look, I know these things can be stubborn, but it\'s all going to be worth it in the end.$B$BTrust me.', 27602), -- New Babies
(34819, 1, 1, 0, 0, 'I heard the worst rumor about how you have to obtain those things.$B$BSomething about talbuk first eating them and then \'processing\' them, and then... well, I don\'t want to talk about it.', 27602), -- Fruitful Ventures
(34811, 1, 1, 0, 0, 'Do you have the Nagrand Antiquities?', 27602), -- Good Help is Hard to Find
(35350, 0, 0, 0, 0, 'Banthar\'s horn. Hemet would be green with envy to have another shot at such a powerful beast.', 27602), -- Queen of the Clefthoof
(35357, 6, 6, 0, 0, 'How goes the hunt for Tall Buck?', 27602), -- King of the Breezestriders
(36273, 0, 1, 0, 0, 'Have you dealt with the podlings in Spiteleaf Thicket?', 27602), -- Whacking Weeds
(34512, 1, 1, 0, 0, 'Do you have the saberon claws I asked for?', 27602), -- Declawing The Competition
(34662, 0, 1, 0, 0, 'What are you waiting for? Get in the ring and start spilling blood!', 27602), -- Ring of Trials: Crushmaul
(34869, 6, 6, 0, 0, 'Windrocs? Yeah, Nagrand\'s filthy with them.$B$BThey seem to like high places and rock outcroppings.$B$BI don\'t know. What do I look like - a windroc whisperer? You\'re the $c.', 27602), -- Tastes Like Chicken
(35928, 25, 25, 0, 0, 'I have plenty of meat. You should buy some.$B$BWhat I really need are bones. Nagrand\'s animals are the heartiest on all of Draenor. They have the finest-quality bones.$B$BI\'m making the tastiest soup you\'ve ever tried. I\'ll show that Grogglefitz who the best cook truly is.', 27602), -- Meatgut Needs Bones
(35338, 6, 6, 0, 0, 'This outsider really thinks she can come here and best me in my own land?$B$BOh... sorry, commander. Present company excluded, of course.', 27602), -- Shooting the Breeze
(35337, 274, 274, 0, 0, 'It\'s unbelievable how arrogant these rangari can be.', 27602), -- That Pounding Sound
(34952, 0, 25, 0, 0, 'Why do I have the distinct feelin\' that you\'re not quite done at Hallvalor, $g boyo:girlie;?', 27602), -- The Friend o' My Enemy
(34769, 0, 6, 0, 0, 'We just need your decision, $n. Are we making a corral or a tankworks?', 27602), -- A Choice to Make
(34746, 547, 0, 0, 0, 'Good news?', 0), -- Shields Down!
(34719, 0, 0, 0, 0, 'I\'m having trouble seeing. I may not have long.', 27602), -- ... and My Hammer
(34718, 0, 0, 0, 0, 'I\'ll never forgive myself.', 27602), -- The Others
(34678, 1, 1, 0, 0, '$n, I can\'t tell you how great it is to see you.', 27602), -- Up and Running
(36385, 0, 0, 0, 0, 'What have you got there, commander?', 27602), -- Legacy of the Ancients
(34448, 0, 1, 0, 0, 'Are you prepared to confront Kaelynara?', 27602), -- Kaelynara Sunchaser
(34415, 1, 1, 0, 0, 'Do you have the crystal giant heart?', 27602), -- An'dure The Giant
(34406, 0, 1, 0, 0, 'Have you returned the injured miners to safety?', 27602), -- Caught In The Chaos
(34403, 1, 1, 0, 0, 'Have you collected enough arcane essence yet?', 27602), -- Arcane Essence
(34400, 0, 1, 0, 0, 'Have you used the Arcane Dissipator on the Manafeeders yet?', 27602), -- Frenzied Manafeeders
(33944, 1, 0, 0, 0, 'Where did you find Ricky?!', 0), -- And the Elekk Too?!
(33884, 0, 1, 0, 0, 'Is it safe to go in the forest again?', 27602), -- Sher'KHAAAAAAANNNN!
(33882, 0, 1, 0, 0, 'Did you find my missing peachick friends?!', 27602), -- Just Peachicky
(34164, 0, 0, 0, 0, 'Yes?', 27602), -- Book Burning
(35254, 0, 396, 0, 0, 'Are Teron\'gor\'s foul demonic minions fleeing to the Twisting Nether with their tails between their legs?', 27602), -- Retribution for the Light
(35227, 0, 1, 0, 0, 'I hope you\'ve extended our diplomatic hand to our ogre friends.', 27602), -- Ogre Diplomacy
(34092, 0, 0, 0, 0, 'Were you able to acquire the aid of the Ango\'rosh?', 27602), -- Desperate Measures
(33976, 1, 1, 0, 0, 'We need the final piece of the Heart!', 27602), -- The Final Piece
(33988, 0, 0, 0, 0, 'Restalaan would be happy to know that someone fulfilled his wishes.', 0), -- Invasion of the Soul Eaters
(34013, 0, 0, 0, 0, 'Some things are worth fighting for, $r. These are such things.', 27602), -- Never Forget
(34234, 0, 0, 0, 0, 'We will run from their kind no longer.', 27602), -- Payback
(33969, 0, 1, 0, 0, 'We cannot afford another enemy in this war.', 27602), -- Vile Defilers
(33967, 5, 5, 0, 0, 'Do you have the fangs? We don\'t have much time!', 27602), -- Antivenin
(33958, 6, 6, 0, 0, 'Did the demon have Sha\'tari as we thought?', 27602), -- Into the Hollow
(34351, 6, 0, 0, 0, 'Do you have the arkonite pylon and the crystals?', 0), -- We Must Construct Additional Pylons
(34407, 0, 1, 0, 0, 'All of Auchindoun, and the countless souls within, depends on our success.', 27602), -- Holding the Line
(33920, 1, 1, 0, 0, 'I trust you have Karab\'uun. I am not known for my patience when the countless souls inside Auchindoun are in danger.', 27602), -- The Heart of Auchindoun
(34978, 0, 0, 0, 0, 'Were you able to find any weapons?', 27602), -- Prized Repossessions
(34979, 0, 0, 0, 0, 'We need to make sure those Vizier\'s are taken care of before we can deal with Morkurk.', 27602), -- Punching Through
(34977, 0, 0, 0, 0, 'Thaelin said that the flares will surely get his copters attention. I hope those contraptions actually work.', 27602), -- Supply Recovery
(34777, 0, 0, 0, 0, 'I will defend Auchindoun with my life. We cannot lose anymore in this war!', 27602), -- Gatekeepers of Auchindoun
(34802, 1, 1, 0, 0, 'I don\'t know what I would do without Tuliaa... she\'s not just my sister. She\'s my best friend.', 27602), -- A Pilgrimage Gone Awry
(33874, 0, 6, 0, 0, 'Is it done?', 27602), -- Aruumel's Rest
(33761, 0, 0, 0, 0, 'Hm, what is that book you have there?', 0), -- Barum's Notes
(33734, 0, 0, 0, 0, 'These are more than mere objects. They are our livelihood, our past and future, our comfort.$B$BThey are pieces of us.', 0), -- Pieces of Us
(34761, 0, 0, 0, 0, 'Do you have the eel sacs?', 27602), -- Clear!
(33872, 6, 6, 0, 0, 'Do you have enough dust?', 27602), -- Dust of the Dead
(33873, 6, 6, 0, 0, 'Have you collected enough Aruunem berries?', 27602), -- Cure of Aruunem
(33581, 0, 0, 0, 0, 'What kind of sick individual burns a book full of perfectly good dark arts?!', 27602), -- Forbidden Knowledge
(33582, 0, 0, 0, 0, 'Kuuan must be taking great joy in pillaging Veil Shadar. He has no idea that he sealed his fate the day he crossed Kura.', 27602), -- Kura's Vengeance
(33580, 0, 0, 0, 0, 'Will you help us?', 27602), -- The Purge of Veil Shadar
(34465, 0, 0, 0, 0, 'It is so nice to finally be able to research my passion without those interfering bronze dragons showing up.', 0), -- Mysterious Hat
(34463, 0, 0, 0, 0, 'Time magic is a young field of research.', 0), -- Mysterious Ring
(34097, 0, 0, 0, 0, 'You\'ve got a license to shred!', 27602), -- Born to Shred
(34096, 0, 0, 0, 0, 'Take a look!', 27602), -- An Eye for a Spy
(33973, 0, 0, 0, 0, 'The Blademaster must pay...', 27602), -- Dying Wish
(34095, 0, 0, 0, 0, 'I fear that Maraad might be losing the light... if he has not already lost it.', 27602), -- Iron Them Out
(34959, 0, 0, 0, 0, 'Mercy is no longer an option against this enemy.', 27602), -- Dreadpiston
(34094, 0, 0, 0, 0, 'Have you found those pages? These manuals are ridiculous.', 27602), -- Vol. X Pages ?
(34090, 0, 0, 0, 0, 'BOOM! Ahahahahaaa!', 27602), -- Thaelin's Quick Fix
(34088, 0, 0, 0, 0, 'Have you slain our enemies?', 27602), -- Too Many Irons in the Fire
(34089, 0, 0, 0, 0, 'Have you found the Iron Horde Explosives yet?', 27602), -- In Short Supply
(34087, 0, 0, 0, 0, 'Take a look through Thaelin\'s Observicopter. I don\'t trust that machine.', 27602), -- Through the Looking Glass
(34804, 0, 6, 0, 0, 'Is the alpha male dispatched?', 27602), -- Not In Your House
(34773, 6, 6, 0, 0, 'Commander! Have ye had a moment to deal with the saberon?', 27602), -- Why Is The Brew Gone?
(34105, 0, 6, 0, 0, 'Proof?$B$BCommander, I am at your service. Your word is all the proof I need.', 27602), -- Wanted: Ra'tok the Hammer
(34104, 0, 6, 0, 0, 'Have you had time to kill Hilaani?', 0), -- Wanted: Hilaani
(34103, 6, 6, 0, 0, 'Any luck tracking down that bird, commander?', 27602), -- Wanted: Kil'uun
(34624, 0, 0, 0, 0, 'Fascinating isn\'t it? The gas is extremely corrosive to almost anything.', 27602), -- Gas Guzzlers
(34573, 0, 0, 0, 0, 'I\'m going to need a lot of iridium dust to purify the metal to anywhere near my masters standards.', 27602), -- Iridium Recovery
(34571, 0, 0, 0, 0, 'We need to get that ore before those goren eat it all.', 27602), -- Out of Jovite
(34558, 0, 66, 0, 0, 'At your command.', 27602), -- At Your Command
(33633, 0, 0, 0, 0, 'That rotten meat looks gross. Find rooter something healthy to eat.', 27602), -- Rooter the Ravenous
(36442, 0, 0, 0, 0, 'Do you have something for me, little beast?', 0), -- Taking the Death Bloom
(36441, 0, 0, 0, 0, 'The saberon should definitely NOT have any of the herbs you have found!', 0), -- Reclaiming Property
(36575, 0, 0, 0, 0, 'We must eradicate the Iron Horde.', 27602), -- Strike While the Iron is Hot
(35235, 0, 0, 0, 0, 'How goes your search?', 27602), -- Iyu
(35234, 0, 0, 0, 0, 'Not fond of this place. If the plants ain\'t tryin\' to kill you then the ground is tryin\' to swallow ya up.', 0), -- Will of the Genesaur
(35233, 0, 0, 0, 0, 'Ya got that ammo?', 27602), -- Just In Case
(35229, 0, 0, 0, 0, 'All in a day\'s work, eh Commander?', 27602), -- Down the Goren Hole
(35209, 0, 0, 0, 0, 'Now I see why some become Rangari. This is exciting.', 0), -- The Life Spring
(35207, 0, 0, 0, 0, 'Me mother always said: \"Burrian! Eat yer veggies!\"$b$bGoing to make her proud today.', 27602), -- Coalpart's Revenge
(36523, 0, 0, 0, 0, 'Ogron are ornery enough. I dunna think we need angrier plant ones on top of that.', 27602), -- A Green Ogron?
(35205, 0, 0, 0, 0, 'If I survive this, I\'m gonna get even by becomin\' a vegetarian.', 27602), -- Burn the Bodies
(35206, 0, 0, 0, 0, 'We had always revered the botani back in Shadowmoon. Now, I see them for the horror they can become.', 27602), -- Bushwhacker
(35204, 0, 0, 0, 0, 'Do you have the pollen?', 27602), -- Pollen Power
(35216, 0, 0, 0, 0, 'What have ya found?', 0), -- Super Seeds
(35214, 0, 0, 0, 0, 'One truth of Gorgrond: death is not the worst thing that can happen to you.', 27602), -- The Infested
(35213, 0, 0, 0, 0, 'Curse them botani and their ilk.', 27602), -- The Razorbloom
(35652, 0, 0, 0, 0, 'Glyza is good with tools.', 0), -- Growing Wood
(35647, 0, 0, 0, 0, 'Those pods are critical $p, I need them!', 27602), -- A Grim Harvest
(35645, 0, 0, 0, 0, 'Where are my mushrooms?!', 27602), -- The Secret of the Fungus
(35644, 0, 0, 0, 0, 'Truly a grim task, bringing mercy to the infected...', 27602), -- Mercy for the Living
(35633, 0, 0, 0, 0, 'The families of my squad need closure and we need more information on their deaths.', 0), -- Scout Forensics
(35063, 0, 0, 0, 0, 'Buildin\' an outpost out here requires a certain kind o\' crazy.', 27602), -- We Need An Outpost
(35050, 0, 0, 0, 0, 'It is no small thing for us to welcome so many strangers into our camps. Gorgrond is not the sort of place that breeds trust easily.', 27602), -- Rescue Rangari
(35055, 0, 0, 0, 0, 'I came here to fight the Blackrock clan, not get lost in the jungle.', 27602), -- Lost Mole Machines
(37149, 0, 396, 0, 0, 'You do know that any time you waste talking to me brings us closer to doom, right?', 0), -- The Void-Gate
(37155, 0, 396, 0, 0, 'Did you find the compass?', 0), -- The Brass Compass
(39055, 0, 0, 0, 0, 'Get that ship started yet?', 27602), -- Ship Shape
(39054, 0, 0, 0, 0, 'You memorize those blueprints yet?', 27602), -- Shipbuilding
(38259, 6, 0, 0, 0, 'I\'ll need building materials, commander. You can\'t build docks from mud.', 0), -- All Hands on Deck
(38256, 0, 0, 0, 0, 'I will rebuild.', 27602), -- Hook, Line, and... Sink Him!
(38254, 0, 0, 0, 0, 'Commander, it\'s you! Naielle promised she would send someone.', 0), -- Derailment
(37151, 0, 396, 0, 0, 'Leave me alone.', 0), -- Cold Steel
(37164, 0, 396, 0, 0, 'Did you find anything?', 0), -- The Huntresses
(37087, 0, 0, 0, 0, 'Hello commander, what can I do for you?', 27602), -- Lost in Transition
(38354, 0, 0, 0, 0, 'Did you find Apprentice Var\'nath?', 27602), -- Portable Portals
(36848, 0, 0, 0, 0, 'Did you activate a waygate?', 27602), -- Ogre Waygates
(36316, 0, 0, 0, 0, 'Let us finish what we have started.', 27602), -- Victory is Within Reach
(34924, 0, 0, 0, 0, 'Were you able to find the stolen raven eggs?', 0), -- The Egg Thieves
(34939, 0, 0, 0, 0, 'It is written in the Scroll of Sermons that the Raven Mother is not patient, and neither am I.$b$bDo you have the paws of the Bloodmane for me?', 0), -- Declawing The Bloodmane
(34922, 0, 0, 0, 0, 'We must have all the sacred texts! We cannot afford to leave even a single one unaccounted for!', 27602), -- Words of the Raven Mother
(34923, 0, 0, 0, 0, 'The Bloodmane will not shake our faith.$b$bHowever, if you could kill a few more it would make it easier for the Raven Mother to hear our prayers.', 27602), -- The Bloodmane
(34991, 0, 0, 0, 0, 'Tillik\'s disappearance caused great sadness to the Flock.', 27602), -- To the... Rescue?
(35634, 0, 0, 0, 0, 'Did you bring the device?', 0), -- Control is King
(35261, 0, 0, 0, 0, '<A comfortable-looking chair with a socket in the arm rest.>', 0), -- Shot-Caller
(35260, 0, 0, 0, 0, 'Impressive, aren\'t they? My own creation.$B$BA simple wooden effigy bearing just a pinch of enchantment.', 27602), -- Hardly Working
(35258, 0, 0, 0, 0, 'The Apexis had every advantage, and yet they vanished. What could have happened?', 27602), -- Legacy of the Apexis
(34883, 0, 0, 0, 0, 'You know those elixirs you have been so eagerly quaffing?$B$BThey are made of this stuff.', 27602), -- A Feast of Shadows
(34882, 0, 0, 0, 0, 'Put the poor fool down before he hurts somebody.', 27602), -- Blades in the Dark
(34829, 0, 0, 0, 0, 'Replacing their hands with weapons...$B$BWho does that?!', 27602), -- New Neighbors
(34828, 0, 0, 0, 0, 'Have you found the orb?', 27602), -- Ishaal's Orb
(34886, 0, 0, 0, 0, '<Ikky looks up at you, foot clamped in his beak, and lets out a muffled cheep.>', 27602), -- Baby Bird
(34884, 0, 0, 0, 0, 'Any word on Skizzik?', 27602), -- The Kaliri Whisperer
(35245, 0, 0, 0, 0, 'Hm? What\'s that you have there?', 0), -- A Sentimental Relic
(35013, 0, 0, 0, 0, 'Who... are you? Why have you stirred me?', 0), -- Lithic's Gift
(35011, 0, 0, 0, 0, 'Have you silenced the false king?', 27602), -- The False Talon King
(35002, 0, 0, 0, 0, '<A large bowl awaits an offering for the raven god.>', 0), -- Sons of Sethe
(35000, 0, 0, 0, 0, 'Without Anzu\'s gift, the curse would have consumed us all.', 27602), -- Banished From the Sky
(34998, 0, 0, 0, 0, 'Reshad sent an outsider here? You must be very important... or very dangerous.', 0), -- Talon Watch
(34999, 0, 0, 0, 0, 'My attempts to bottle the pooled blood have failed. It breaks down and dissipates when it is taken away from Sethe\'s bones.$B$BBut I have high hopes for this congealed form!', 27602), -- Hatred Undying
(35675, 0, 0, 0, 0, 'Oh, commander! What an honor!$B$BHow can I help you?', 0), -- Wanted: Spineslicer's Husk
(37287, 0, 6, 0, 0, 'Have ye dealt with Mr. Anders yet, commander?', 27602), -- Cleaning House
(36048, 604, 604, 0, 0, 'I don\'t want to stick around here any longer than we need to.', 27602), -- We Have Him Now
(36023, 0, 0, 0, 0, 'These orcs are soulless brutes. They canna be reasoned with.', 27602), -- Extrinsic Motivation
(35959, 0, 0, 0, 0, 'This is no time to be havin\' a moral dilemma. We need answers tae complete our mission.', 27602), -- The Power of Poison
(35926, 6, 0, 0, 0, 'Did ye find anything?', 0), -- Assassin's Mark
(35408, 396, 396, 0, 0, 'I hope you\'re toting a cannon and some balls, soldier.', 27602), -- Prime the Cannons
(35407, 0, 396, 0, 0, 'What\'s your report, soldier?', 27602), -- Punishable by Death
(35353, 0, 396, 0, 0, 'Is the creature dead?', 27602), -- A Piece of the Puzzle
(35339, 1, 0, 0, 0, 'Everything is so hazy... what happened? Who are you?', 0), -- A Parting Favor
(35329, 396, 0, 0, 0, 'I\'d recognize one of my schematics anywhere.', 0), -- I See Dead People
(35674, 6, 6, 0, 0, 'Pleasure to see you, $Gsir:madame;.', 27602), -- Wanted: Keeho's Severed Paw
(35286, 0, 66, 0, 0, 'Glory to your forces, commander.', 27602), -- Orders, Commander?
(35274, 0, 1, 0, 0, 'I had really hoped to have given you a better impression when you came out here.', 27602), -- One of Our Own
(35668, 0, 0, 0, 0, 'To hold such a treasure. I wonder if that Sun-Talon had any idea of the significance?', 0), -- Syth's Secret
(35636, 0, 0, 0, 0, 'Here, I\'ll take them both for safekeeping.', 0), -- All Due Respect
(34659, 0, 0, 0, 0, 'You would be wise to turn back, traveler.', 27602), -- The Crone
(34658, 0, 0, 0, 0, '<Reshad fastens another scroll to Percy, who squawks meekly in protest.>$B$BOh, stop whining.', 27602), -- Orders From On High
(34656, 0, 0, 0, 0, 'Wingblades forged in the name of a sun god to bring freedom and glory to her children.$B$BA mask worn by a great king who would walk among his people in disguise to know their true nature.', 27602), -- Hidden in Plain Sight
(34657, 0, 0, 0, 0, 'Skettis will fall today. Neither of us can change that.$B$BWe need only to send them a message: we will not die quietly.', 27602), -- Adherents of the Sun God
(36428, 0, 0, 0, 0, 'Any progress to report with that cure?', 27602), -- Curing With Force
(35211, 0, 0, 0, 0, 'I\'m almost done here. Have you placed all those firebombs yet?', 27602), -- Preventing the Worst
(35091, 0, 0, 0, 0, 'Did you put down those spore creatures yet?', 27602), -- Sporicide
(35089, 0, 0, 0, 0, 'Do ya have that oil for me yet?', 0), -- Skimming Off the Top
(35090, 0, 0, 0, 0, 'Got any parts for me?', 0), -- The Right Parts for the Job
(36384, 0, 0, 0, 0, 'Have you completed the field test, $n?', 27602), -- Field Trial
(35081, 0, 0, 0, 0, 'I still see a mess of wasps down there.$b$bWe need to clear those wasps out before I can get the salvage operation started.', 27602), -- Clearing Out Before Cleaning Up
(35082, 0, 0, 0, 0, 'Did you rescue everyone you could?', 27602), -- Getting the Crew Back Together
(35079, 0, 0, 0, 0, 'We\'re working our butts off here! Whadya want?', 27602), -- Spore-be-Gone
(35077, 0, 0, 0, 0, 'I\'d love to be out there burning them spores down but I got paperwork to do here.$b$bSpeaking of work, you done yet?', 27602), -- Defungination
(38356, 0, 0, 0, 0, 'Collect a Bass Blaster, Laz-Tron Disc Reader, Phonic Amplifier, S.P.R.K. Capacitor, and a Cord of Ancient Wood.', 27602); -- Bringing the Bass

DELETE FROM `quest_request_items` WHERE `ID` IN (36629 /*Inspiring Ashran*/, 36448 /*Reduction in Force*/, 33084 /*The Big Haul*/, 37322 /*The Prophet's Final Message*/, 33837 /*Darkness Falls*/, 34054 /*The Dark Side of the Moon*/, 33795 /*Across the Stars*/, 33794 /*The Great Salvation*/, 35032 /*Into Anguish*/, 36194 /*Sharper Blades, Bigger Timber*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(36629, 0, 0, 0, 0, 'How did your walk go?', 27602), -- Inspiring Ashran
(36448, 6, 6, 0, 0, 'Did you deliver the... notice of termination?', 27602), -- Reduction in Force
(33084, 0, 0, 0, 0, 'Have ya seen tha size a these beasts?', 27602), -- The Big Haul
(37322, 0, 0, 0, 0, 'The arcanum hums in your hand as you get close to the memorial.', 0), -- The Prophet's Final Message
(33837, 0, 0, 0, 0, 'Today is the day that everything ends. But something new rises from the ashes.', 27602), -- Darkness Falls
(34054, 0, 0, 0, 0, 'Ner\'zhul will pay for what he has done.', 27602), -- The Dark Side of the Moon
(33795, 0, 0, 0, 0, 'Your aid is appreciated, $c.', 0), -- Across the Stars
(33794, 0, 0, 0, 0, 'You bring hope and salvation to us all, champion.', 27602), -- The Great Salvation
(35032, 0, 0, 0, 0, 'Is it done?', 27602), -- Into Anguish
(36194, 547, 0, 0, 0, 'Did you harvest that timber sample yet?', 0); -- Sharper Blades; Bigger Timber

DELETE FROM `quest_request_items` WHERE `ID` IN (39365 /*Equipment Blueprint: Ghostly Spyglass*/, 34032 /*Privileged Information*/, 34031 /*Something to Remember Me By*/, 34048 /*"Mole Machine, Go Home"*/, 34466 /*Mysterious Staff*/, 37968 /*Assault on the Temple of Sha'naar*/, 39433 /*Unseen Influence*/, 39067 /*Upgrading The Fleet*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(39365, 0, 0, 0, 0, 'Those look like some equipment blueprints!', 0), -- Equipment Blueprint: Ghostly Spyglass
(34032, 0, 0, 0, 0, 'That book has my working notes from the last five years. It\'s too dangerous to leave behind!', 27791), -- Privileged Information
(34031, 0, 0, 0, 0, 'Don\'t be shy with those mines, I got plenty.', 27791), -- Something to Remember Me By
(34048, 0, 0, 0, 0, 'If the voice command fails, you can always try the manual override.$B$BYe simply hold down the control pedal, shift into reverse, and pull the escape lever at the same time.', 27791), -- "Mole Machine, Go Home"
(34466, 0, 0, 0, 0, 'I did my time with fire and the other arcane arts. They were good. Nothing compares to hurling a giant ball of fire.$b$bBut temporal wizardry? So much fun!$b$bReally hard to master but you always have plenty of time.', 0), -- Mysterious Staff
(37968, 0, 6, 0, 0, 'How goes the attack, $gsir:ma\'am;?', 27791), -- Assault on the Temple of Sha'naar
(39433, 0, 0, 0, 0, 'I fear even your help may not be enough to avert the doom of the Arakkoa.', 0), -- Unseen Influence
(39067, 0, 0, 0, 0, 'Finding success on these new naval missions?', 0); -- Upgrading The Fleet

DELETE FROM `quest_request_items` WHERE `ID` IN (38717 /*Black Rook Prison*/, 38714 /*Maiev's Trail*/, 39117 /*Shriek No More*/, 38647 /*For the Corn!*/, 38646 /*A Sight For Sore Eyes*/, 38645 /*Children of the Night*/, 40567 /*Enter the Nightmare*/, 43702 /*Softening the Target*/, 38684 /*Reading the Leaves*/, 41707 /*Wormtalon Wreckage*/, 38671 /*Lost in Retreat*/, 38655 /*Root Cause*/, 38662 /*Tears for Fears*/, 39354 /*Wisp in the Willows*/, 42747 /*Where the Wildkin Are*/, 42748 /*Emerald Sisters*/, 38862 /*Thieving Thistleleaf*/, 40221 /*Spread Your Lunarwings and Fly*/, 40220 /*Thorny Dancing*/, 38225 /*Death to the Witchmother*/, 38235 /*Solid as a Rock*/, 38144 /*The Demons Below*/, 38145 /*Out of the Dream*/, 38455 /*Frenzied Furbolgs*/, 42423 /*Archmage Vargoth's Retreat*/, 42171 /*Final Exit*/, 42206 /*The Next Level Has Arrived*/, 42149 /*Some Knowledge Shouldn't Be Shared*/, 42435 /*Prepare To Be Assimilated*/, 38203 /*Challiane Vineyards*/, 38232 /*Minion! Kill Them!*/, 37657 /*Making the World Safe for Profit*/, 37528 /*Let Sleeping Giants Lie*/, 37542 /*No Time for Tryouts*/, 37507 /*Boss Whalebelly's in Charge*/, 42368 /*Quantity Over Quality*/, 42367 /*Arkethrax*/, 42369 /*They're Doing it Wrong*/, 42375 /*Eye See You*/, 37469 /*The Tidestone: Shattered*/, 37730 /*The Headmistress' Keys*/, 37729 /*Pop Quiz: Advanced Rune Drawing*/, 42371 /*Study Hall: Combat Research*/, 42370 /*Wanding 101*/, 37678 /*Hit the Books*/, 37736 /*Dressing With Class*/, 42694 /*Back from the Dead*/, 42692 /*Children of Nar'thalas*/, 42693 /*You Never Know Until You Scry*/, 37486 /*Nar'thalas Still Suffers*/, 37257 /*Our Very Bones*/, 37492 /*A Rather Long Walk*/, 37728 /*Presentation is Everything*/, 37727 /*The Magister of Mixology*/, 37256 /*They Came From the Sea*/, 38014 /*Feasting on the Dragon*/, 38015 /*On the Brink*/, 37959 /*The Hunger Returns*/, 37960 /*Leyline Abuse*/, 37859 /*The Consumed*/, 37856 /*The Withered*/, 42271 /*Their Dying Breaths*/, 37450 /*Saving Stellagosa*/, 37658 /*Reignite the Wards*/, 37653 /*Demon Souls*/, 42696 /*Tech It Up A Notch*/, 42429 /*Memories of Ebonchill*/, 42479 /*The Mage Hunter*/, 42455 /*Alodi's Gems*/, 42477 /*Daio the Decrepit*/, 42476 /*The Deadwind Site*/, 42452 /*Finding Ebonchill*/, 42687 /*Troops in the Field*/, 42127 /*Building Our Troops*/, 42126 /*Archmage Omniara*/, 41141 /*A Conjuror's Duty*/, 41036 /*The Dreadlord's Prize*/, 38944 /*Sew It Begins*/, 39875 /*The Last Few*/, 40593 /*Demons Among Us*/, 40517 /*The Fallen Lion*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(38717, 0, 0, 0, 0, 'Do you have the keys?', 0), -- Black Rook Prison
(38714, 0, 0, 0, 0, 'We will give this area a thorough search.', 27843), -- Maiev's Trail
(39117, 1, 1, 0, 0, 'Papa always said the only way he\'d leave here would be feet-first.$B$BI wish he\'d been wrong.', 27843), -- Shriek No More
(38647, 0, 0, 0, 0, 'The corn isn\'t gonna gather itself.', 27843), -- For the Corn!
(38646, 0, 0, 0, 0, 'Heh? Is that you again?', 27843), -- A Sight For Sore Eyes
(38645, 0, 0, 0, 0, 'The attackers are night elves, yes, but they are not the same night elves I once knew.', 27843), -- Children of the Night
(40567, 0, 0, 0, 0, 'Is he alive? Will my husband return to me?', 27843), -- Enter the Nightmare
(43702, 0, 0, 0, 0, 'Have you managed to thin their numbers?', 27843), -- Softening the Target
(38684, 0, 0, 0, 0, 'Ahh... the fear! The panic!$b$bI haven\'t the strength to fight much longer...', 0), -- Reading the Leaves
(41707, 0, 0, 0, 0, 'Have you taken vengeance for us, yet?', 27843), -- Wormtalon Wreckage
(38671, 0, 0, 0, 0, 'Have you retrieved them?', 27843), -- Lost in Retreat
(38655, 0, 0, 0, 0, 'Have you collected the root samples?', 27843), -- Root Cause
(38662, 0, 0, 0, 0, 'Do you have the Tears of Elune?', 27843), -- Tears for Fears
(39354, 0, 0, 0, 0, 'Any luck?', 27843), -- Wisp in the Willows
(42747, 0, 0, 0, 0, 'Owlbeasts are fierce protectors and dangerous when lost to us.', 27843), -- Where the Wildkin Are
(42748, 0, 0, 0, 0, 'May Elune guide your path.', 27843), -- Emerald Sisters
(38862, 0, 0, 0, 0, 'Gather as many eggs as you can and bring them back to me. I will keep them safe.', 0), -- Thieving Thistleleaf
(40221, 0, 0, 0, 0, 'Please help the poor Lunarwings. They are such gentle creatures.', 27843), -- Spread Your Lunarwings and Fly
(40220, 0, 0, 0, 0, 'Have you dealt with those Thorndancers yet?', 27843), -- Thorny Dancing
(38225, 0, 1, 0, 0, 'Has the terrible deed been accomplished, traveler?', 27843), -- Death to the Witchmother
(38235, 0, 1, 0, 0, 'Have you roused my disciples, traveler?', 27843), -- Solid as a Rock
(38144, 0, 0, 0, 0, 'This was no accident. Someone intended us to sleep forever.', 27843), -- The Demons Below
(38145, 0, 0, 0, 0, 'The Druids of the Claw must awaken. We are needed.', 27843), -- Out of the Dream
(38455, 0, 0, 0, 0, 'Did it work?', 27843), -- Frenzied Furbolgs
(42423, 0, 0, 0, 0, 'What have you discovered, $n?', 27843), -- Archmage Vargoth's Retreat
(42171, 0, 0, 0, 0, 'I thought I\'d snoop around a bit before I met you at the rotunda. Unfortunately my invisibility spell wore off at an inopportune time. I\'m glad you found me! What is this you have found, $n?', 0), -- Final Exit
(42206, 0, 0, 0, 0, 'Do you think we\'ve reduced their numbers enough?', 27843), -- The Next Level Has Arrived
(42149, 0, 0, 0, 0, 'I hope we\'ve found all of the books.', 27843), -- Some Knowledge Shouldn't Be Shared
(42435, 0, 0, 0, 0, 'Have you found the Pearl and scrolls?', 0), -- Prepare To Be Assimilated
(38203, 0, 0, 0, 0, 'Have you found the pieces of the recipe?', 0), -- Challiane Vineyards
(38232, 0, 0, 0, 0, 'This land is ripe for the taking. Especially the olives. They are really ripe. And I love ripe olives.', 0), -- Minion! Kill Them!
(37657, 0, 6, 0, 0, 'How goes the cleanup?', 27843), -- Making the World Safe for Profit
(37528, 0, 0, 0, 0, 'As soon as I can, I\'ll arm the gladiators in Oceanus Cove.', 27843), -- Let Sleeping Giants Lie
(37542, 0, 274, 0, 0, 'By giving that hozen a good beating, you\'ll be making a spot for yourself in the arena.\n\nYou don\'t have to kill him, though.', 27843), -- No Time for Tryouts
(37507, 0, 1, 0, 0, 'Go on. Go talk to him.', 27843), -- Boss Whalebelly's in Charge
(42368, 0, 0, 0, 0, 'Demons that can summon other demons are not the kind of demons we should leave alive.', 27843), -- Quantity Over Quality
(42367, 0, 0, 0, 0, 'I find your tactics... interesting.', 27843), -- Arkethrax
(42369, 0, 0, 0, 0, 'Did you see the look on those demons\' faces? Priceless!', 27843), -- They're Doing it Wrong
(42375, 0, 0, 0, 0, 'Don\'t ask where I got the eye. Worst case is I tell you and then it gets all awkward between us.', 27843), -- Eye See You
(37469, 0, 0, 0, 0, '<The last remaining piece of the Tidestone lies before you.>', 0), -- The Tidestone: Shattered
(37730, 0, 0, 0, 0, 'Were you able to meet with the headmistress?', 0), -- The Headmistress' Keys
(37729, 0, 0, 0, 0, 'Go on, then! Get those feet moving!', 27843), -- Pop Quiz: Advanced Rune Drawing
(42371, 0, 0, 0, 0, 'I agree. Research can be grueling work.', 27843), -- Study Hall: Combat Research
(42370, 0, 0, 0, 0, 'You\'ll never learn if you never practice.', 27843), -- Wanding 101
(37678, 0, 0, 0, 0, '<The librarian sighs quietly.>', 27843), -- Hit the Books
(37736, 0, 0, 0, 0, 'Still trying to get into the academy, I see.', 27843), -- Dressing With Class
(42694, 0, 0, 0, 0, 'Thank you for your aid, $c.', 27843), -- Back from the Dead
(42692, 0, 0, 0, 0, 'We\'ve hit a dead end here. Any luck out there?', 27843), -- Children of Nar'thalas
(42693, 0, 0, 0, 0, 'I would have brought my own spell foci if SOMEONE hadn\'t been rushing me...', 27843), -- You Never Know Until You Scry
(37486, 0, 0, 0, 0, 'I will make it up to them. WE will make it up to them.', 27843), -- Nar'thalas Still Suffers
(37257, 0, 0, 0, 0, 'My people may not care much for me, but that will not stop me from caring for them.', 27843), -- Our Very Bones
(37492, 0, 0, 0, 0, 'Have you seen him?', 27843), -- A Rather Long Walk
(37728, 6, 6, 0, 0, 'Yes? You have the eyes?', 27843), -- Presentation is Everything
(37727, 6, 6, 0, 0, 'Are we speaking again because you have my eggs?', 27843), -- The Magister of Mixology
(37256, 0, 0, 0, 0, '<The nightwatcher looks at you expectantly.>', 27843), -- They Came From the Sea
(38014, 0, 0, 0, 0, 'Yes, $n?', 27843), -- Feasting on the Dragon
(38015, 0, 0, 0, 0, 'Hurry, $n!', 27843), -- On the Brink
(37959, 0, 0, 0, 0, 'Do you have them? Please tell me you have them, my friend.', 27843), -- The Hunger Returns
(37960, 0, 0, 0, 0, 'With each one of these cretins you slay, I grow stronger.', 27843), -- Leyline Abuse
(37859, 0, 0, 0, 0, 'Clever $r. Yes, a ley crystal should bring them back to their senses.', 0), -- The Consumed
(37856, 0, 0, 0, 0, 'Yes?', 27843), -- The Withered
(42271, 0, 0, 0, 0, 'Oh no...', 0), -- Their Dying Breaths
(37450, 1, 0, 0, 0, 'If there\'s a remnant of the Blue Dragonflight nearby, we should do whatever we can to ally ourselves with them.', 0), -- Saving Stellagosa
(37658, 0, 1, 0, 0, 'All of the wards need to be reignited if we\'re to hold the front.', 27843), -- Reignite the Wards
(37653, 0, 1, 0, 0, 'We need those demon souls, $n.', 27843), -- Demon Souls
(42696, 0, 0, 0, 0, 'Our future is in your hands.', 27843), -- Tech It Up A Notch
(42429, 0, 6, 0, 0, 'Seek out the memories of the former Council members. None are here in the upper floors of the tower, and none would be in the sewers. <Cough> Check the public squares, the inns, the lower floors of the tower, the streets... A sharp eye is your ally.', 27843), -- Memories of Ebonchill
(42479, 0, 1, 0, 0, 'Do you have it?', 27843), -- The Mage Hunter
(42455, 1, 1, 0, 0, 'You found everything in my vault? I hope the defenses weren\'t a bother.', 27843), -- Alodi's Gems
(42477, 1, 1, 0, 0, 'Well, what did Daio have to say?', 27843), -- Daio the Decrepit
(42476, 1, 1, 0, 0, 'I trust you were successful?', 27843), -- The Deadwind Site
(42452, 0, 1, 0, 0, 'Have we found what we need yet?', 27843), -- Finding Ebonchill
(42687, 0, 0, 0, 0, 'How did it go?', 27843), -- Troops in the Field
(42127, 0, 0, 0, 0, 'How did the training go?', 27843), -- Building Our Troops
(42126, 0, 0, 0, 0, 'How is the mission proceeding?', 27843), -- Archmage Omniara
(41141, 0, 0, 0, 0, '', 27843), -- A Conjuror's Duty
(41036, 0, 0, 0, 0, 'We must hurry!', 27843), -- The Dreadlord's Prize
(38944, 0, 0, 0, 0, 'I wouldn\'t mind working with some cashmere...', 27843), -- Sew It Begins
(39875, 0, 0, 0, 0, 'Almost done enchanting those vellums?', 0), -- The Last Few
(40593, 0, 669, 0, 0, 'I never suspected they had infiltrated my own throne room! Praise the Light you were here!', 27843), -- Demons Among Us
(40517, 0, 0, 0, 0, 'Welcome, $n. I am pleased you survived the battle. You have something for me?', 27843); -- The Fallen Lion

DELETE FROM `quest_request_items` WHERE `ID` IN (51352 /*Don't Play with Matches*/, 51339 /*Cleaning Bills*/, 50803 /*I Want It All Now*/, 50774 /*No Bot Left Behind*/, 50753 /*Earl-E Bot Gets the Worm*/, 50741 /*Don't Turtle*/, 50814 /*A Horrible Place*/, 50696 /*Fun With Magnets*/, 50691 /*Not On Our Payroll*/, 50704 /*Anchors Aweigh Too Much*/, 50674 /*Two Faced Pirate Scum*/, 50802 /*Iron Low Tide*/, 50810 /*Break 'Em Out*/, 51712 /*Eye for an Eye*/, 51720 /*Get Shredded*/, 51723 /*Saw Dusted*/, 51728 /*Burn It All Down*/, 51752 /*Grizzled*/, 51711 /*Having a Blast*/, 51217 /*WANTED: Yarsel'ghun*/, 50909 /*Never Outgunned*/, 50910 /*Dangerous Game*/, 50908 /*Smells Like Trouble*/, 49755 /*Heavy Artillery*/, 49744 /*Bombs, Away*/, 49746 /*Dousing the Flames*/, 49745 /*You Have Their Orders*/, 50780 /*Oathbound*/, 50611 /*Storm's Vengeance*/, 50610 /*Gathering Storm*/, 50608 /*Forbidden Rites*/, 50593 /*A Bloody Mess*/, 50595 /*No Quarter*/, 50594 /*Beneath the Veil*/, 52795 /*A Saur Point*/, 50162 /*Sticky Situation*/, 50168 /*Royal Succession*/, 50161 /*Recovering Raimond*/, 50070 /*Detective Mildenhall*/, 49997 /*Storm's Judgment*/, 50139 /*The Missing Link*/, 49996 /*Rearmament*/, 49995 /*Fabricated Fabrications*/, 52796 /*Sometimes Less Is More*/, 52793 /*Circle the Wagons*/, 49704 /*Haywire Harvesters*/, 49706 /*Proclamation Investigation*/, 49705 /*Unnecessary Duress*/, 51490 /*Border Issues*/, 52800 /*Tol Dagor: The Ashvane Overseer*/, 49720 /*Free Bird*/, 50249 /*A Boralus Triple Threat*/, 49716 /*A Lesson on Trust*/, 49734 /*Targeting a Turncoat*/, 51226 /*Death from Two Sides*/, 49733 /*Patching Up the Rear*/, 48367 /*Those Aren't Fish Eggs*/, 48368 /*Deep Sea Defilement*/, 48372 /*Eldritch Invocations*/, 49431 /*Warm and Cozy*/, 49419 /*Frozen*/, 49710 /*An Offering of Eggs*/, 49412 /*Helping Henry*/, 49395 /*The Bears and the Bees*/, 51368 /*WANTED: The Hornet*/, 49394 /*Hold Still*/, 48366 /*Paddle to Safety*/, 49299 /*Enemy Within*/, 48008 /*Dangerous Cargo*/, 48365 /*The Young Lord Stormsong*/, 51384 /*WANTED: Quartermaster Ssylis*/, 48009 /*Betrayal of the Guard*/, 48356 /*Possessive Headgear*/, 48354 /*Tainted Shipments*/, 48355 /*Evacuate the Premises*/, 48353 /*Pulse of the Wharf*/, 49292 /*Algae Shakes*/, 48348 /*Stinging Barbs*/, 48352 /*A Cure from the Sea*/, 49268 /*Sharks in the Water*/, 48540 /*Aiding the Wharf*/, 50059 /*Can't Hear A Thing*/, 47755 /*Captured and Enraptured*/, 48088 /*No Party Like a Trogg Party*/, 48004 /*Beginner Equitation*/, 48005 /*Be Our Guest*/, 48899 /*Safety First*/, 48902 /*Monstrous Energy*/, 48898 /*Lucky Charm*/, 48778 /*Stone Soup*/, 48196 /*Following Eddie's Trail*/, 48195 /*Troublesome Troglodytes*/, 48616 /*Bolas and Birds*/, 48080 /*An Element of Danger*/, 48077 /*The Stoat Hunt*/, 48965 /*Settle the Score*/, 52258 /*She Sells Seashells*/, 49232 /*Salvaging a Disaster*/, 49233 /*I'm a Druid, Not a Priest*/, 49229 /*The Ruins Fought Back*/, 49234 /*A Marine Out of Water*/, 49467 /*Witch of the Woods*/, 49450 /*Incident Reports*/, 49454 /*Pest Prevention*/, 49468 /*Required Webinar*/, 48557 /*Sowing Saplings*/, 49453 /*Give a Dam*/, 49452 /*Inventory Deficit*/, 49465 /*Maximizing Resources*/, 51358 /*WANTED: Gryphon 'Nappers*/, 51144 /*A Bundle of Furs*/, 51568 /*Ritualistic Preparations*/, 48752 /*A Need For Coal*/, 51569 /*The Zandalar Campaign*/, 51715 /*War of Shadows*/, 50352 /*Pinch of Azerite*/, 49066 /*Encase of Emergency*/, 49028 /*A Sweater for Rupert*/, 48879 /*A Hunt for Hawk Eggs*/, 49069 /*WANTED: Ol' Frostclaw*/, 48874 /*Pardon Our Rust*/, 49897 /*Making Mysteries*/, 49531 /*The Beauty of Marketing*/, 51426 /*Inspection Gadget*/, 51430 /*Reverse Tinkering*/, 52148 /*Freehold: A Pirate's End*/, 49757 /*Cat on a Hot Copper Roof*/, 49740 /*Cease Fire!*/, 49736 /*For Kul Tiras!*/, 49738 /*Hands Off My Booty!*/, 52787 /*Numbing the Pain*/, 49737 /*Air Raid*/, 52750 /*Farmers Who Fight*/, 52431 /*No-Landing Zone*/, 49399 /*The Big Job*/, 49400 /*Recruiting Efforts*/, 49403 /*Rodrigo's Revenge*/, 49402 /*Flew the Coop*/, 49407 /*Trixie Business*/, 49290 /*Aged to Perfection*/, 49398 /*Raise a Glass!*/, 49401 /*Rodrigo's Roost*/, 48776 /*Rig Robbing*/, 48774 /*The Beatings Will Continue*/, 48558 /*The Irontide Crew*/, 48773 /*Papers, Please*/, 48539 /*Freehold*/, 48516 /*Toxic Community*/, 49181 /*Glimmering Locket*/, 49230 /*Local Flavor*/, 49226 /*Silencing the Sisters*/, 49178 /*My Favorite Things*/, 53041 /*Sampling the Goods*/, 50573 /*Message from the Management*/, 47487 /*Labor Dispute*/, 47486 /*Suspicious Shipments*/, 47186 /*Sanctum of the Sages*/, 46729 /*The Old Knight*/, 52462 /*A Load of Scrap*/, 47098 /*Out Like Flynn*/, 51211 /*The Heart of Azeroth*/, 46268 /*A Found Memento*/, 47182 /*Long Overdue*/, 47554 /*Intercepting the Legion's Plans*/, 47102 /*The Mysterious Missive*/, 46511 /*We're Treasure Hunters*/, 46510 /*Ship Graveyard*/, 46509 /*Tomb Raidering*/, 47139 /*Mark of the Sentinax*/, 46251 /*Shard Times*/, 46782 /*Further Advancement*/, 45586 /*Shield Amplification*/, 45614 /*Lady Remor'za*/, 44770 /*Secrets of the Shal'dorei*/, 44768 /*Nyell's Workshop*/, 46339 /*Keymaster Orlis*/, 46335 /*The Vault of the Tirisgarde*/, 45064 /*Felborne No More*/, 45062 /*Resisting Arrest*/, 45066 /*Experimental Instability*/, 45065 /*Survey the City*/, 45063 /*The Felsoul Experiments*/, 44736 /*Gates of the Nighthold*/, 44740 /*Staging Point*/, 44830 /*Learning From the Dead*/, 44829 /*We Need Weapons*/, 44827 /*Citizens' Army*/, 44845 /*Break An Arm*/, 44842 /*Shield, Meet Spell*/, 44834 /*Nullified*/, 44844 /*Powering Down the Portal*/, 44843 /*Crystal Clearing*/, 41916 /*A Better Future*/, 44831 /*Taking a Promenade*/, 47654 /*Seat of the Triumvirate: The Crest of Knowledge*/, 47220 /*A Beacon in the Dark*/, 47219 /*A Vessel Made Ready*/, 47217 /*Sources of Darkness*/, 47218 /*The Shadowguard Incursion*/, 47184 /*Arkhaan's Peril*/, 47100 /*Arkhaan's Pain*/, 47180 /*The Pulsing Madness*/, 47101 /*Arkhaan's Prayers*/, 48074 /*Looming Over Me*/, 47690 /*The Defiler's Legacy*/, 47687 /*Gatekeeper's Challenge: Mastery*/, 47685 /*Gatekeeper's Challenge: Cunning*/, 47689 /*Gatekeeper's Challenge: Tenacity*/, 47688 /*Invasive Species*/, 47882 /*Conservation of Magic*/, 47066 /*Consecrating Ground*/, 46834 /*Khazaduum, First of His Name*/, 47991 /*Dark Machinations*/, 47989 /*Heralds of Apocalypse*/, 47990 /*A Touch of Fel*/, 47988 /*Chaos Theory*/, 47987 /*Preventive Measures*/, 47986 /*Scars of the Past*/, 49293 /*Invasion Onslaught*/, 48799 /*Fuel of a Doomed World*/, 48642 /*Argussian Reach*/, 43415 /*A Hero's Weapon*/, 48441 /*Remnants of Darkfall Ridge*/, 47967 /*An Argus Roper*/, 48455 /*Duskcloak Problem*/, 49015 /*Antorus, the Burning Throne: The Death of a Titan*/, 47287 /*The Vindicaar Matrix Core*/, 49143 /*Essence of the Light Mother*/, 47652 /*The Light Mother*/, 47508 /*Fire At Will*/, 46213 /*Legionfall: Emberfire*/, 48500 /*A Moment of Respite*/, 47627 /*Vengeance*/, 48513 /*Invasion Point Offensive*/, 45861 /*A Gift From the Six*/, 45126 /*Unlikely Seduction*/, 45916 /*The Acolyte Imperiled*/, 45192 /*Runes of Rending*/, 45187 /*Secrets in the Underbelly*/, 45185 /*Message from the Shadows*/, 45524 /*The Forgotten Heir*/, 46501 /*Grave Robbin'*/, 46499 /*Spiders, Huh?*/, 46247 /*Defending Broken Isles*/, 46245 /*Begin Construction*/, 46286 /*Legionfall Supplies*/, 46805 /*The Deceiver's Downfall*/, 46253 /*Pillars of Creation*/, 46765 /*The Broken Shore: Investigating the Legion*/, 47330 /*Whispers of a Frightened World*/, 41207 /*Supplies Needed: Leystone*/, 42959 /*Three Is a Lucky Number*/, 42940 /*When There's a Will, There's a Way*/, 42707 /*A Magical Affliction*/, 44563 /*Redemption for the Fallen*/, 45316 /*Stabilizing Suramar*/, 44754 /*Waxing Crescent*/, 44723 /*More Like Me*/, 44724 /*Missing Persons*/, 44955 /*Visitor in Shal'Aran*/, 38695 /*Crackdown*/, 39781 /*Neltharion's Lair*/, 45175 /*Soul Prism of the Illidari*/, 44481 /*Destiny Unfulfilled*/, 44480 /*In My Father's House*/, 44414 /*Felspawns of Lothros*/, 44466 /*An Unclear Path*/, 44464 /*Awakenings*/, 38949 /*So You Think You Can Sew*/, 38948 /*Hard Times*/, 38947 /*Runic Catgut*/, 41499 /*Squid Out of Water*/, 41001 /*Shatter the Sashj'tar*/, 40336 /*Turning the Tidemistress*/, 41709 /*Breaking Down the Big Guns*/, 40364 /*Bubble Trouble*/, 41618 /*The Seawarden*/, 41410 /*Dry Powder*/, 40334 /*Fisherman's Tonic*/, 40332 /*Beach Bonfire*/, 40331 /*Bite of the Sashj'tar*/, 40320 /*Band of Blood Brothers*/, 42955 /*The Proper Way of Things*/, 43569 /*Arluin's Request*/, 41231 /*Apex Predator*/, 41258 /*Fruit of the Doom*/, 43994 /*Feed Thalyssra*/, 43564 /*Flow Control*/, 43563 /*Ephemeral Manastorm Projector*/, 43587 /*Leyline Feed: Elor'shan*/, 43588 /*Leyline Feed: Kel'balor*/, 43562 /*Giving It All We've Got*/, 43362 /*The Stuff of Dreams*/, 43361 /*Fragments of Disaster*/, 42491 /*Long Buried Knowledge*/, 43314 /*Beware the Fury of a Patient Elf*/, 42490 /*Opening the Arcway*/, 44562 /*Growing Strong*/, 43318 /*Ly'leth's Champion*/, 43813 /*Sanctum of Order Teleporter Online!*/, 43317 /*In the Bag*/, 43315 /*Death Becomes Him*/, 43312 /*Thinly Veiled Threats*/, 43311 /*Or Against Us*/, 43352 /*Asset Security*/, 42841 /*A Big Score*/, 42840 /*If Words Don't Work...*/, 43969 /*Hired Help*/, 42835 /*The Old Fashioned Way*/, 42834 /*Intense Concentration*/, 42832 /*The Fruit of Our Efforts*/, 42489 /*Thalyssra's Drawers*/, 41230 /*Trapping Evolved*/, 41215 /*They Become The Hunted*/, 40617 /*Turn Around, Nighteyes*/, 41256 /*Blast of Spice Fish*/, 41107 /*Bad Apples*/, 41915 /*The Master's Legacy*/, 43811 /*Lunastre Estate Teleporter Online!*/, 41466 /*Estate Jewelry: Haute Claw-ture*/, 41465 /*Estate Jewelry: A Braggart's Brooch*/, 42521 /*The Enemy of My Enemy...*/, 42488 /*Thalyssra's Abode*/, 40642 /*Power! Get The Power!*/, 40919 /*Fel Bent for Leather*/, 40713 /*The Black Tome*/, 40657 /*The Road to Fel*/, 40683 /*Discovery Requires Experimentation*/, 40625 /*A Different Source*/, 41097 /*Shard of Vorgos*/, 41098 /*Shard of Kozak*/, 41214 /*Parts 0*/, 41222 /*Into The Pit!*/, 43594 /*Leyline Feed: Halls of the Eclipse*/, 41140 /*Search and Rescue!*/, 41139 /*The Key Is Around Here Somewhere...*/, 40929 /*Symbols of Power*/, 40328 /*A Fate Worse Than Dying*/, 40901 /*Grimwing the Devourer*/, 40898 /*Fresh Meat*/, 40307 /*Glaive Circumstances*/, 41575 /*Felsoul Teleporter Online!*/, 40469 /*Final Preparations*/, 40370 /*Purge the Unclean*/, 40348 /*Something in the Water*/, 40368 /*Turtle Powered*/, 43591 /*Leyline Feed: Ley Station Aethenar*/, 43592 /*Leyline Feed: Falanaar Arcway*/, 43593 /*Leyline Feed: Falanaar Depths*/, 42722 /*Friends in Cages*/, 40947 /*Special Delivery*/, 40730 /*Redistribution*/, 41148 /*Dispensing Compassion*/, 41320 /*Pry It From Their Cold, Feral Claws*/, 41307 /*All That Glitters*/, 41123 /*An Artisan's Mark*/, 45056 /*Noressa*/, 41494 /*Eminent Grow-main*/, 41485 /*Moonwhisper Rescue*/, 41480 /*Managazer*/, 41479 /*Natural Adversaries*/, 41475 /*Prongs and Fangs*/, 41474 /*Fertilizing the Future*/, 41197 /*You've Got to Be Kitten Me Right Meow*/, 44561 /*Seed of Hope*/, 42225 /*Breaking the Seal*/, 41453 /*Homeward Bounding*/, 41452 /*Feline Frantic*/, 43590 /*Leyline Feed: Ley Station Moonfall*/, 40324 /*Arcane Communion*/, 40970 /*The Orchestrator of Our Demise*/, 41032 /*Stop the Spell Seekers*/, 40965 /*Lay Waste, Lay Mines*/, 40967 /*Precious Little Left*/, 41030 /*Sigil Reclamation*/, 43808 /*Moon Guard Teleporter Online!*/, 40321 /*Feathersong's Redemption*/, 40319 /*The Final Ingredient*/, 40315 /*End of the Line*/, 40306 /*The Last Chapter*/, 40308 /*Fragments of Memory*/, 40300 /*Tools of the Trade*/, 40744 /*An Ancient Recipe*/, 40266 /*The Lost Advisor*/, 43809 /*Tel'anor'eporter Online!*/, 41028 /*Power Grid*/, 43106 /*Feed Oculeth*/, 40747 /*The Delicate Art of Telemancy*/, 40798 /*Cling to Hope*/, 42147 /*First Contact*/, 42079 /*Masquerade*/, 41989 /*Blood of My Blood*/, 41834 /*The Masks We Wear*/, 41760 /*Kel'danath's Legacy*/, 41702 /*Written in Stone*/, 40796 /*Lingering on the Edge*/, 44672 /*Ancient Mana*/, 40009 /*Arcane Thirst*/, 44448 /*In the House of Light and Shadow*/, 44153 /*Light's Charge*/, 43705 /*Nobundo's Last Stand*/, 44009 /*A Falling Star*/, 48376 /*Mass Primal Obliterum*/, 48375 /*Primal Obliterum*/, 42483 /*Put It All on Red*/, 39786 /*A Stone Cold Gamble*/, 39792 /*A Stack of Racks*/, 42447 /*Dances With Ravenbears*/, 42445 /*Nithogg's Tribute*/, 42446 /*Singed Feathers*/, 40120 /*A Murky Fate*/, 42645 /*Spilling Bad Blood*/, 42641 /*What the Bonespeakers Buried*/, 42640 /*The Value of Knowledge*/, 42639 /*A Stone of Blood*/, 42635 /*The Mystery of Dreyrgrot*/, 39405 /*Stories of Battle*/, 40005 /*Stormheim's Salvation*/, 40002 /*A Familiar Fate*/, 39061 /*Whispers from the Dark*/, 39060 /*Combustible Contagion*/, 40078 /*A Heavy Burden*/, 39853 /*Victory is Eternal*/, 39851 /*Allies in Death*/, 39850 /*Sundered*/, 39849 /*To Light the Way*/, 39848 /*A Desperate Bargain*/, 38347 /*Stealth by Seaweed*/, 38324 /*Accessories of the Cursed*/, 38339 /*A Little Kelp From My Foes*/, 38817 /*Regal Remains*/, 38808 /*Bjornharta*/, 38810 /*The Dreaming Fungus*/, 39788 /*The Runewood's Revenge*/, 38778 /*Turn the Keys*/, 43596 /*Piercing the Mists*/, 40044 /*Shadows in the Mists*/, 43595 /*To Honor the Fallen*/, 40046 /*Scavenging the Shallows*/, 44721 /*Helya's Conquest*/, 44771 /*A Threat Rises*/, 39804 /*Speaking of Bones*/, 39787 /*Rigging the Wager*/, 39793 /*Only the Finest*/, 38342 /*Another Way*/, 38405 /*To Weather the Storm*/, 39593 /*The Shattered Watcher*/, 39592 /*A Trial of Will*/, 39591 /*A Trial of Valor*/, 39595 /*Blood and Gold*/, 39590 /*Ahead of the Game*/, 38558 /*See Ya Later, Oscillator*/, 38053 /*Assault and Battery*/, 38036 /*Supplies From the Skies*/, 38052 /*Boarded!*/, 38035 /*A Royal Summons*/, 41778 /*Fire it Up*/, 39986 /*Magic Message*/, 40991 /*Opening the Test Kitchen*/, 44055 /*They Have A Pitlord*/, 39772 /*Can't Hold a Candle To You*/, 40345 /*Burn the Candle at Both Ends*/, 40339 /*Candle of Command*/, 39768 /*Candle to the Grave*/, 39765 /*Wax On, Wax Off*/, 39656 /*Wolf Pack Attack*/, 40000 /*A True Hunter*/, 39670 /*Critter Scatter Shot*/, 40594 /*Justice Rains from Above*/, 42088 /*Evacuate Snowmane*/, 39777 /*Buy Us Time*/, 39862 /*The Siegebrul*/, 39776 /*Battle Worms*/, 42630 /*Bolas Bastion*/, 39867 /*I'm Not Lion!*/, 39178 /*Moose on the Loose*/, 40228 /*Scout It Out*/, 40216 /*A Hunter at Heart*/, 39392 /*Bear Huntin'*/, 39124 /*Moose Shootin'*/, 39123 /*Lion Stalkin'*/, 39859 /*Note-Eating Goats*/, 40170 /*Amateur Hour*/, 40230 /*Oh, the Clawdacity!*/, 40102 /*Murlocs: The Next Generation*/, 40049 /*Slime Time*/, 40047 /*I'll Huff, I'll Puff...*/, 40045 /*Nature vs. Nurture*/, 39439 /*Stonedark Relics*/, 39437 /*Deep in the Cavern*/, 39438 /*Guhruhlruhlruh*/, 39440 /*You Lift, Brul?*/, 39426 /*Blood Debt*/, 39588 /*They Will Pay With Blood*/, 39425 /*Stonedark Crystal*/, 39391 /*Pet Rocks*/, 39374 /*An Audience with Torok*/, 39373 /*Hags of a Feather*/, 39372 /*Witch of the Wood*/, 39774 /*Demon Detainment*/, 39764 /*Shiny, But Deadly*/, 39429 /*Assaulting the Haglands*/, 39321 /*The Three*/, 44207 /*Portal Full of Shiny Things*/, 39318 /*Nursing the Wounds*/, 39419 /*Hex-a-Gone*/, 42622 /*Ceremonial Drums*/, 39133 /*No Time to Talk*/, 39134 /*Wrathshard*/, 42596 /*Mountainstrider Round-Up*/, 42590 /*Moozy's Reunion*/, 40520 /*To See the Past*/, 40167 /*The Story of Huln*/, 39027 /*Dargrul and the Hammer*/, 39043 /*Bitestone Enclave*/, 39487 /*Crystal Fury*/, 39489 /*Invading Spelunkers*/, 39488 /*Balance of Elements*/, 39614 /*Fish Out of Water*/, 39316 /*Trapped Tauren*/, 39277 /*Spray and Prey*/, 39491 /*Ormgul the Pestilent*/, 39490 /*Infestation*/, 39272 /*Poisoned Crops*/, 42424 /*Following In His Footsteps*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(51352, 0, 0, 0, 0, 'Get to work, the battle is not won yet!', 27980), -- Don't Play with Matches
(51339, 0, 0, 0, 0, 'Don\'t waste time.  There is much cleaning to do.', 27980), -- Cleaning Bills
(50803, 0, 0, 0, 0, 'I want every piece of that treasure in there.', 27980), -- I Want It All Now
(50774, 0, 0, 0, 0, 'What? Earl-E isn\'t going to help himself!', 27980), -- No Bot Left Behind
(50753, 0, 0, 0, 0, 'Do you have the meat yet?', 27980), -- Earl-E Bot Gets the Worm
(50741, 0, 0, 0, 0, 'You deal with that Tortollan yet?', 27980), -- Don't Turtle
(50814, 0, 0, 0, 0, 'Save the turtles.', 27980), -- A Horrible Place
(50696, 0, 0, 0, 0, 'I like gold, let\'s find some!', 0), -- Fun With Magnets
(50691, 0, 0, 0, 0, 'Do what I say, we\'ll get along a lot better!', 27980), -- Not On Our Payroll
(50704, 0, 0, 0, 0, 'See what you can find out in the mud.', 27980), -- Anchors Aweigh Too Much
(50674, 0, 0, 0, 0, 'Hurry $p you\'ve got to kill the ettin.', 27980), -- Two Faced Pirate Scum
(50802, 0, 0, 0, 0, 'Show the Irontide they aren\'t tough enough to hang around here!', 27980), -- Iron Low Tide
(50810, 0, 0, 0, 0, 'You need to break the chains!', 27980), -- Break 'Em Out
(51712, 0, 1, 0, 0, 'Make them pay for what they\'ve done to us.', 27980), -- Eye for an Eye
(51720, 1, 0, 0, 0, '<Energized Core required.>', 0), -- Get Shredded
(51723, 0, 1, 0, 0, 'How many d\'ya get?', 27980), -- Saw Dusted
(51728, 0, 11, 0, 0, 'Well at least the flamethrower hasn\'t blown up on ya yet.', 27980), -- Burn It All Down
(51752, 0, 1, 0, 0, 'Did you find him?', 27980), -- Grizzled
(51711, 1, 1, 0, 0, 'They won\'t stand a chance!', 27980), -- Having a Blast
(51217, 0, 0, 0, 0, 'The wanted poster is nailed to the wall, with tasks etched on it.', 27980), -- WANTED: Yarsel'ghun
(50909, 0, 0, 0, 0, 'We\'ll need more than that. Find us some weapons!', 0), -- Never Outgunned
(50910, 0, 0, 0, 0, 'We need your help getting rid of these keenblades.', 27980), -- Dangerous Game
(50908, 0, 0, 0, 0, 'Those scent vials should help you eliminate both Force Commanders.', 27980), -- Smells Like Trouble
(49755, 0, 669, 0, 0, 'If that cannon can reach Brennadam, it can reach those zeppelins!', 27980), -- Heavy Artillery
(49744, 669, 669, 0, 0, 'Don\'t forget to check inside the buildings too!', 27980), -- Bombs, Away
(49746, 0, 669, 0, 0, 'My town is still burning, $c!', 27980), -- Dousing the Flames
(49745, 669, 669, 0, 0, 'You find those orders?', 27980), -- You Have Their Orders
(50780, 661, 0, 0, 0, 'You do have the rod, right?', 0), -- Oathbound
(50611, 0, 1, 0, 0, 'Whenever you are ready.', 27980), -- Storm's Vengeance
(50610, 0, 6, 0, 0, 'Are the rods in position?', 27980), -- Gathering Storm
(50608, 0, 1, 0, 0, 'These horrors must be destroyed.', 27980), -- Forbidden Rites
(50593, 0, 0, 0, 0, 'What is that you have there?', 0), -- A Bloody Mess
(50595, 0, 0, 0, 0, 'We can\'t hold this forever!', 27980), -- No Quarter
(50594, 0, 0, 0, 0, 'Have the grasps been dealt with?', 27980), -- Beneath the Veil
(52795, 0, 0, 0, 0, 'I\'m not leaving till Sourtooth is dead!', 27980), -- A Saur Point
(50162, 1, 1, 0, 0, 'You get all the jelly yet?', 27980), -- Sticky Situation
(50168, 1, 1, 0, 0, 'Oooh, ooh, do you have it!?', 27980), -- Royal Succession
(50161, 0, 0, 0, 0, 'It is about time someone came looking for me!', 0), -- Recovering Raimond
(50070, 0, 0, 0, 0, 'Did you find anything else?', 0), -- Detective Mildenhall
(49997, 0, 396, 0, 0, 'This must be done.', 27980), -- Storm's Judgment
(50139, 1, 0, 0, 0, 'We need to get to the bottom of all this before Lord Stormsong goes on the offensive!', 0), -- The Missing Link
(49996, 1, 1, 0, 0, 'There are still many who don\'t follow Lord Stormsong. We need to stand by them.', 27980), -- Rearmament
(49995, 6, 6, 0, 0, 'Any luck recovering those blueprints?', 27980), -- Fabricated Fabrications
(52796, 0, 0, 0, 0, 'I still see a lot of Saurolisk around.', 27980), -- Sometimes Less Is More
(52793, 0, 0, 0, 0, 'I\'m getting worried, they should have been here hours ago.', 27980), -- Circle the Wagons
(49704, 6, 6, 0, 0, 'Any luck? The mainsprings are usually brittle and easily damaged.', 27980), -- Haywire Harvesters
(49706, 0, 0, 0, 0, 'Lord Stormsong is a bit aloof, but his power over the tides is beyond measure.', 27980), -- Proclamation Investigation
(49705, 0, 0, 0, 0, 'We must help these poor souls.', 27980), -- Unnecessary Duress
(51490, 0, 1, 0, 0, 'We have to stop this!', 27980), -- Border Issues
(52800, 0, 0, 0, 0, 'Well?', 27980), -- Tol Dagor: The Ashvane Overseer
(49720, 0, 0, 0, 0, 'Any luck? Hopefully they didn\'t nip you too much.', 27980), -- Free Bird
(50249, 0, 0, 0, 0, 'What is it?', 27980), -- A Boralus Triple Threat
(49716, 0, 0, 0, 0, 'Did you bring me those badges?', 27980), -- A Lesson on Trust
(49734, 0, 0, 0, 0, 'Has the task been finished?', 27980), -- Targeting a Turncoat
(51226, 0, 0, 0, 0, 'Have you thinned out those saurolisks yet?', 27980), -- Death from Two Sides
(49733, 0, 0, 0, 0, 'My gratitude, that should help alleviate some of the soldiers\' pain.', 27980), -- Patching Up the Rear
(48367, 0, 1, 0, 0, 'Ah, the satisfying squish of a monster egg under your boot. What a feeling!', 27980), -- Those Aren't Fish Eggs
(48368, 0, 1, 0, 0, 'My mind is bursting with the tide\'s cries. It is almost too much to bear.', 27980), -- Deep Sea Defilement
(48372, 0, 1, 0, 0, 'I trusted Deepwarden. He always seemed a good man.$b$bNevertheless, we cannot allow such blasphemy.', 27980), -- Eldritch Invocations
(49431, 1, 0, 0, 0, 'I need more steam! Hurry, the tub is getting chilly!', 0), -- Warm and Cozy
(49419, 0, 0, 0, 0, 'Woo \'ave somefin?', 27980), -- Frozen
(49710, 1, 0, 0, 0, 'You find a safe nest.', 0), -- An Offering of Eggs
(49412, 0, 1, 0, 0, 'That thing sure hates bees...', 27980), -- Helping Henry
(49395, 0, 0, 0, 0, 'Bears giving you trouble?', 27980), -- The Bears and the Bees
(51368, 0, 1, 0, 0, 'What do you want, $n?', 27980), -- WANTED: The Hornet
(49394, 0, 0, 0, 0, 'Got the fur?', 27980), -- Hold Still
(48366, 0, 1, 0, 0, 'I can\'t sit idly by anymore.', 27980), -- Paddle to Safety
(49299, 0, 669, 0, 300, 'After the guard fell, it was easy to get to everybody else.', 27980), -- Enemy Within
(48008, 0, 669, 0, 300, 'If I had only noticed sooner, perhaps some of this could be avoided.', 27980), -- Dangerous Cargo
(48365, 0, 396, 0, 0, 'I have failed in my duty as a guard.', 27980), -- The Young Lord Stormsong
(51384, 0, 1, 0, 0, '<Alby nods at you.>', 27980), -- WANTED: Quartermaster Ssylis
(48009, 0, 396, 0, 0, 'I feel no pity for those who gave their humanity for power.', 27980), -- Betrayal of the Guard
(48356, 0, 1, 0, 0, 'Our priority is saving our people. We must do whatever we can.', 27980), -- Possessive Headgear
(48354, 0, 1, 0, 0, 'I fear that if even a single worm-ridden shipment is allowed to leave Anglepoint, this plague will spiral out of our control.', 27980), -- Tainted Shipments
(48355, 0, 1, 0, 0, 'We\'ve already witnessed one innocent death today. We cannot allow any more!', 27980), -- Evacuate the Premises
(48353, 0, 1, 0, 0, 'The merchants here generally have a thumb on the pulse of the wharf. If anybody�s noticed anything strange in town, its them.', 27980), -- Pulse of the Wharf
(49292, 0, 1, 0, 0, 'This remedy was passed down to me from the tidesages that came before.$b$bI just hope it helps us now.', 27980), -- Algae Shakes
(48348, 1, 1, 0, 0, 'Be careful with those stingers, $n! They\'d put someone of your frame down easily!', 27980), -- Stinging Barbs
(48352, 1, 1, 0, 0, 'The sea cannot offer its guidance when it is in such pain. I feel as if one of my senses is blinded.', 27980), -- A Cure from the Sea
(49268, 0, 1, 0, 0, 'The sea\'s creatures travel where they may find food, but they carry danger with them.', 27980), -- Sharks in the Water
(48540, 1, 1, 0, 0, 'My day-to-day job usually just consists of blessing the ships, reading the waters, finding the best spots to fish�$b$bI fear that this may be out of my league.', 27980), -- Aiding the Wharf
(50059, 0, 1, 0, 0, 'Guess beauty is in the eye of the beholder?', 27980), -- Can't Hear A Thing
(47755, 0, 0, 0, 0, 'Were you able to free my men? Without them, I\'m stranded!', 27980), -- Captured and Enraptured
(48088, 0, 22, 0, 0, 'Troggs on the estate grounds? What meaning is this!?', 27980), -- No Party Like a Trogg Party
(48004, 0, 0, 0, 0, 'Kul Tiran riding is a true show of mastery and sport!', 27980), -- Beginner Equitation
(48005, 0, 1, 0, 0, 'Have you taken your tour yet? Take a break from adventuring and relax!', 27980), -- Be Our Guest
(48899, 1, 1, 0, 0, 'Protection, yes. Can\'t put yourself in a dangerous situation without the proper protection!', 27980), -- Safety First
(48902, 1, 1, 0, 0, 'My dad will be so excited when he sees his favorite drink!', 27980), -- Monstrous Energy
(48898, 1, 1, 0, 0, 'Tails are real lucky, $n. I think this one will give my dad heaps of courage!', 27980), -- Lucky Charm
(48778, 0, 0, 0, 0, 'The flavor of the soup doesn\'t seem quite right. It must be missing ingredients.', 0), -- Stone Soup
(48196, 1, 0, 0, 0, 'Are... are you here to save me?', 0), -- Following Eddie's Trail
(48195, 0, 1, 0, 0, 'The troggs attack passers-by and take whatever... or whomever... they want for food. Enough is enough!', 27980), -- Troublesome Troglodytes
(48616, 0, 1, 0, 0, 'Our retrievers are workers. They aid us in our hunting ventures.', 27980), -- Bolas and Birds
(48080, 1, 1, 0, 0, 'Boars actually present some semblance of challenge to the hunter.', 27980), -- An Element of Danger
(48077, 1, 1, 0, 0, 'Have you collected enough stoat pelts?', 27980), -- The Stoat Hunt
(48965, 0, 1, 0, 0, 'Though my lifeblood drains, all I yearn for is vengeance.', 27980), -- Settle the Score
(52258, 0, 0, 0, 0, 'Come, let us parley... How was that? I\'m trying to sound like a proper shell seller.', 27980), -- She Sells Seashells
(49232, 0, 0, 0, 0, 'Did you find enough relics?', 27980), -- Salvaging a Disaster
(49233, 0, 0, 0, 0, 'Have you tried out that staff yet?', 27980), -- I'm a Druid, Not a Priest
(49229, 0, 0, 0, 0, 'Did ye clear out those constructs? The bloodthirsty things aren\'t helpin\' anyone by bein\' in there.', 27980), -- The Ruins Fought Back
(49234, 0, 0, 0, 0, 'Is there something you need?', 27980), -- A Marine Out of Water
(49467, 1, 0, 0, 0, 'My son told me about the witch, $n. I\'ve come up here to take care of her! If you want something done right, you need to do it yourself.', 0), -- Witch of the Woods
(49450, 0, 1, 0, 0, 'Have you looked those beasts in the eye? Something is quite unnatural about them.', 27980), -- Incident Reports
(49454, 0, 1, 0, 0, 'I will admit to not being the biggest fan of spiders. Fewer spiders sounds pretty good to me.', 27980), -- Pest Prevention
(49468, 0, 0, 0, 0, 'If they\'ve been in the woods this whole time, the lumberjacks must have seen something that will help us in our investigation.', 27980), -- Required Webinar
(48557, 0, 1, 0, 0, 'After pain, there is always rebirth. Even for Azeroth!', 27980), -- Sowing Saplings
(49453, 0, 1, 0, 0, 'Between the logging and the giant spiders, the beavers are in such danger!', 27980), -- Give a Dam
(49452, 1, 1, 0, 0, 'I spend my own money to get these workers the supplies they need and they just go ahead and lose them! How much more generous must I be?', 27980), -- Inventory Deficit
(49465, 1, 1, 0, 0, 'I give them an honest job with good pay. This is the thanks I get?', 27980), -- Maximizing Resources
(51358, 0, 1, 0, 0, 'Is this about the wanted sign? You better hurry, a good number of hunters are after it as well.', 27980), -- WANTED: Gryphon 'Nappers
(51144, 1, 0, 0, 0, 'Welcome to my inn, friend! How can  I help ya?', 0), -- A Bundle of Furs
(51568, 0, 0, 0, 0, 'Did you get the storm silver? Don\'t forget that it needs to be blessed.', 27980), -- Ritualistic Preparations
(48752, 0, 0, 0, 0, 'Have you gone to the foundry yet?', 27980), -- A Need For Coal
(51569, 0, 0, 0, 0, 'We must secure our foothold on Zandalar.', 27980), -- The Zandalar Campaign
(51715, 0, 0, 0, 0, 'Without us, this war would be lost easily.', 27980), -- War of Shadows
(50352, 1, 0, 0, 0, 'Did you bring the dust?', 0), -- Pinch of Azerite
(49066, 1, 0, 0, 0, 'I\'ve heard that destroying some of the larger ice structures in the area angers them, so do what you do best and destroy any that you come across!', 0), -- Encase of Emergency
(49028, 1, 0, 0, 0, 'Is there something you need from me?', 0), -- A Sweater for Rupert
(48879, 0, 0, 0, 0, 'Have you found enough eggs yet? You know what those small goblins say, time is money!', 27980), -- A Hunt for Hawk Eggs
(49069, 0, 0, 0, 0, 'Is this about the wanted sign? You better hurry, a good number of hunters are after it as well.', 27980), -- WANTED: Ol' Frostclaw
(48874, 0, 1, 0, 0, 'Be careful when resetting the traps, and if you get injured by faulty equipment, take it up with Kennings, not me.', 27980), -- Pardon Our Rust
(49897, 0, 1, 0, 0, 'How do my petrifyingly scary chickens look?', 27980), -- Making Mysteries
(49531, 1, 1, 0, 0, 'If your smile isn\'t at least half of the picture, I don\'t want to see it!', 27980), -- The Beauty of Marketing
(51426, 0, 0, 0, 0, 'The machine should beep when it has all of the information it needs.', 27980), -- Inspection Gadget
(51430, 0, 0, 0, 0, 'Did you find anything interesting?', 27980), -- Reverse Tinkering
(52148, 0, 0, 0, 0, 'What\'s say sixty-forty split on the bounty? Eh? \n\nSeventy-thirty?\n\nHow about a finder\'s fee?', 27980), -- Freehold: A Pirate's End
(49757, 0, 0, 0, 0, 'We can\'t leave Scratchy here!', 27980), -- Cat on a Hot Copper Roof
(49740, 0, 0, 0, 0, 'Scuttle means destroy, landlubber! Now go do it!', 27980), -- Cease Fire!
(49736, 0, 0, 0, 0, 'They say a warrior fights twice as hard when he thinks of home.', 27980), -- For Kul Tiras!
(49738, 0, 0, 0, 0, 'What are you waiting for? Get up there and man that cannon!', 27980), -- Hands Off My Booty!
(52787, 0, 0, 0, 0, 'Did you find any evermoss?', 27980), -- Numbing the Pain
(49737, 0, 0, 0, 0, 'Bring down those skyriders!', 27980), -- Air Raid
(52750, 0, 0, 0, 0, 'We need anyone willing and able to fight!', 27980), -- Farmers Who Fight
(52431, 0, 0, 0, 0, 'Please help the guards fend off those pirates!', 27980), -- No-Landing Zone
(49399, 0, 0, 0, 0, 'Find anything?', 0), -- The Big Job
(49400, 0, 0, 0, 0, 'Makes me sick seein\' those damn posters all over this town.', 27980), -- Recruiting Efforts
(49403, 0, 0, 0, 0, 'Go! Go! Go!', 27980), -- Rodrigo's Revenge
(49402, 0, 0, 0, 0, 'Did you find any pretties? Oh, they must be so hungry out there.', 27980), -- Flew the Coop
(49407, 0, 0, 0, 0, 'Stay your hand, friend! If you harm me, you\'ll never find the scroll!', 27980), -- Trixie Business
(49290, 0, 0, 0, 0, 'Are you with the Irontide?$B$BI\'ve already paid you people! Leave me alone!', 0), -- Aged to Perfection
(49398, 0, 0, 0, 0, 'What\'sa matter? Cat got yer tongue?', 27980), -- Raise a Glass!
(49401, 0, 0, 0, 0, 'Talk to Rodrigo and send that evidence off to Taelia.', 27980), -- Rodrigo's Roost
(48776, 0, 0, 0, 0, 'You get my stash?', 27980), -- Rig Robbing
(48774, 0, 0, 0, 0, 'Well is you a merc or isn\'t you? Get to merc\'in!', 27980), -- The Beatings Will Continue
(48558, 0, 0, 0, 0, 'What have you found?', 27980), -- The Irontide Crew
(48773, 0, 0, 0, 0, 'Lady Katherine is as stubborn as a whale shark. She won\'t buy our story without proof.', 27980), -- Papers, Please
(48539, 0, 0, 0, 0, 'Look, I\'m worldly, but I don\'t have anything you can catch from my eyes.$B$BJust use the spyglass, would ya?', 27980), -- Freehold
(48516, 0, 0, 0, 0, 'You got them stingers?', 27980), -- Toxic Community
(49181, 0, 0, 0, 0, 'Hm? What\'s that you\'ve got there?', 0), -- Glimmering Locket
(49230, 0, 0, 0, 0, '<Sam\'s stomach growls audibly.>', 27980), -- Local Flavor
(49226, 0, 0, 0, 0, 'Sirens can be handled with relative ease. The older ones take a bit more work.', 27980), -- Silencing the Sisters
(49178, 0, 0, 0, 0, 'We\'ve all lost something in the tides.$B$BSome more than others.', 27980), -- My Favorite Things
(53041, 0, 0, 0, 0, '<Flynn side-eyes you while trying his best to look casual.>$B$BYou get what we need?', 27980), -- Sampling the Goods
(50573, 0, 0, 0, 0, 'Find anything useful in there?', 0), -- Message from the Management
(47487, 0, 0, 0, 0, 'One of them even got the gall to come out here askin\' about MY whiskey. Told him to suck bilge-water.\n\n<Cagney spits.>\n\nYeah he roughed me up pretty good after that.', 27980), -- Labor Dispute
(47486, 0, 0, 0, 0, 'We need to find out how many more of these new weapons Ashvane has and where they might be sending them.', 27980), -- Suspicious Shipments
(47186, 0, 0, 0, 0, 'The Tidesages abandoned that place months ago when they pulled back to their monasteries. We still don\'t know why.', 27980), -- Sanctum of the Sages
(46729, 0, 0, 0, 0, 'Sorry, I should have mentioned he can be a bit... long-winded at times.', 27980), -- The Old Knight
(52462, 0, 0, 0, 0, 'This machine is gonna change everything!', 0), -- A Load of Scrap
(47098, 0, 0, 0, 0, 'Is that the new powder Flynn was talking about?\n\nI\'ll take it for safekeeping.', 0), -- Out Like Flynn
(51211, 0, 1, 0, 0, 'Ye need tae hear from Azeroth herself, $n.', 27980), -- The Heart of Azeroth
(46268, 403, 0, 0, 0, 'Well met, $n. What brings you to Stormwind this day?', 0), -- A Found Memento
(47182, 0, 0, 0, 0, 'Have you dealt with High Inquisitor Raalgar yet?', 27980), -- Long Overdue
(47554, 669, 0, 0, 0, 'Have you found the orders and the code book?', 0), -- Intercepting the Legion's Plans
(47102, 397, 0, 0, 0, 'Our fight goes on, champion. Argus must fall.$b$bWhat is that you\'ve found?', 0), -- The Mysterious Missive
(46511, 0, 0, 0, 0, 'You fetch that treasure yet?', 0), -- We're Treasure Hunters
(46510, 0, 0, 0, 0, 'I\'m always lookin\' for more treasure!', 27980), -- Ship Graveyard
(46509, 0, 0, 0, 0, 'I\'m always lookin\' for more treasure!', 27980), -- Tomb Raidering
(47139, 0, 0, 0, 0, 'The Sentinax is well defended, but we will crush everything it sends against us.', 0), -- Mark of the Sentinax
(46251, 0, 0, 0, 0, 'Do you have the shards? I hope you kept an accurate count. If you counted wrong, I simply can\'t be held responsible for the consequences.', 0), -- Shard Times
(46782, 0, 0, 0, 0, 'Seek out Chronicler Elrianne.', 27980), -- Further Advancement
(45586, 0, 0, 0, 0, 'How did you do, $n?', 27980), -- Shield Amplification
(45614, 0, 0, 0, 0, 'How did you do, $n?', 27980), -- Lady Remor'za
(44770, 0, 0, 0, 0, 'Have you found some scrolls?', 0), -- Secrets of the Shal'dorei
(44768, 0, 0, 0, 0, 'Were you successful?', 0), -- Nyell's Workshop
(46339, 0, 0, 0, 0, 'Did you find anything?', 0), -- Keymaster Orlis
(46335, 0, 0, 0, 0, 'Have you found anything promising?', 0), -- The Vault of the Tirisgarde
(45064, 0, 0, 0, 0, 'Has the threat been removed?', 27980), -- Felborne No More
(45062, 0, 0, 0, 0, 'There is much to be done.', 27980), -- Resisting Arrest
(45066, 0, 0, 0, 0, 'Scavenging going well? Not too dangerous I hope.', 27980), -- Experimental Instability
(45065, 0, 0, 0, 0, 'Let\'s hope this is survey is our last. I grow quite tired watching you run around all day.', 27980), -- Survey the City
(45063, 0, 0, 0, 0, 'Making progress I assume?', 27980), -- The Felsoul Experiments
(44736, 0, 0, 0, 0, 'Well, that was... unexpected.', 27980), -- Gates of the Nighthold
(44740, 0, 0, 0, 0, 'Has the beacon been activated.', 27980), -- Staging Point
(44830, 0, 0, 0, 0, 'How goes the search?', 27980), -- Learning From the Dead
(44829, 0, 0, 0, 0, 'How goes the search?', 27980), -- We Need Weapons
(44827, 0, 0, 0, 0, 'How is the training going?', 27980), -- Citizens' Army
(44845, 0, 1, 0, 0, 'We must destroy the Arm!', 27980), -- Break An Arm
(44842, 0, 1, 0, 0, 'The nullifier should do most of the work for you. Just watch out for his offensive magic!', 27980), -- Shield, Meet Spell
(44834, 1, 1, 0, 0, 'It is really child\'s play when you consider the magical weaves. I can see the flaws with just a few minutes of study.', 27980), -- Nullified
(44844, 0, 0, 0, 0, 'Kill Ingra, shut down the portal. Clear?', 27980), -- Powering Down the Portal
(44843, 0, 0, 0, 0, 'Each crystal destroyed makes it that much harder to open the portal again.', 27980), -- Crystal Clearing
(41916, 0, 1, 0, 0, 'Each shal\'dorei rescued is both a potential enemy vanquished and a new hope for our people.', 27980), -- A Better Future
(44831, 0, 1, 0, 0, 'Were you able to find them?', 27980), -- Taking a Promenade
(47654, 0, 0, 0, 0, 'It is a heavy burden I have placed upon you, $n. I have faith you will not fail.', 0), -- Seat of the Triumvirate: The Crest of Knowledge
(47220, 6, 0, 0, 0, 'What is this? Such darkness...', 0), -- A Beacon in the Dark
(47219, 1, 0, 0, 0, 'I see the path clearly, $n.', 0), -- A Vessel Made Ready
(47217, 0, 1, 0, 0, 'Locus-Walker and I have some unfinished business to attend to.', 27980), -- Sources of Darkness
(47218, 0, 1, 0, 0, 'Walking the razor\'s edge does have risks, $n.', 27980), -- The Shadowguard Incursion
(47184, 0, 1, 0, 0, 'We must address this threat.', 27980), -- Arkhaan's Peril
(47100, 0, 1, 0, 0, '<Arkhaan mutters incoherently to himself.>', 27980), -- Arkhaan's Pain
(47180, 0, 1, 0, 0, 'His presence raises more questions than it answers.', 27980), -- The Pulsing Madness
(47101, 1, 0, 0, 0, 'Did you find anything interesting?', 0), -- Arkhaan's Prayers
(48074, 0, 0, 0, 0, 'Any luck in finding my loom?', 0), -- Looming Over Me
(47690, 0, 0, 0, 0, 'Archimonde himself... what have we gotten ourselves into?', 0), -- The Defiler's Legacy
(47687, 0, 0, 0, 0, 'Not afraid of a little magic, are you?', 27980), -- Gatekeeper's Challenge: Mastery
(47685, 0, 0, 0, 0, 'Display the Mark of Cunning or leave me alone.', 27980), -- Gatekeeper's Challenge: Cunning
(47689, 0, 0, 0, 0, 'Take all the time you need. Failure is an art, I hear.', 27980), -- Gatekeeper's Challenge: Tenacity
(47688, 0, 0, 0, 0, 'There is always room for a backup plan. Did you find what we seek?', 27980), -- Invasive Species
(47882, 0, 661, 0, 0, 'Did it work? I am curious if that crystal holds enough power to accomplish our goals.', 27980), -- Conservation of Magic
(47066, 0, 0, 0, 0, 'Hurry $n, we cannot let this continue any longer.', 27980), -- Consecrating Ground
(46834, 0, 0, 0, 0, 'Please, they should not be made to suffer any longer.', 0), -- Khazaduum, First of His Name
(47991, 0, 669, 0, 0, 'We do not have time for failure.', 27980), -- Dark Machinations
(47989, 0, 0, 0, 0, 'This may be our only chance to kill one of those sick monsters before we assault Antorus itself.', 27980), -- Heralds of Apocalypse
(47990, 0, 0, 0, 0, 'Remember - immaculate!', 27980), -- A Touch of Fel
(47988, 0, 669, 0, 0, 'We must do whatever it takes to see this done.', 27980), -- Chaos Theory
(47987, 0, 0, 0, 0, 'All who fall nobly deserve to rest in peace.', 27980), -- Preventive Measures
(47986, 0, 0, 0, 0, 'Do you have the components?', 27980), -- Scars of the Past
(49293, 0, 0, 0, 0, 'The offensive continues.', 27980), -- Invasion Onslaught
(48799, 669, 669, 0, 0, 'Victory requires every resource we can muster.', 27980), -- Fuel of a Doomed World
(48642, 0, 0, 0, 0, 'Return to me when you have finished aiding the Argussian Reach, $n.', 27980), -- Argussian Reach
(43415, 0, 0, 0, 0, 'We honor you, $ct.', 27980), -- A Hero's Weapon
(48441, 0, 0, 0, 0, 'Have you found our supplies, $n?', 27980), -- Remnants of Darkfall Ridge
(47967, 0, 0, 0, 0, 'We need those talbuk!', 27980), -- An Argus Roper
(48455, 0, 0, 0, 0, 'These creatures are beautiful, but some must die so others can live.', 27980), -- Duskcloak Problem
(49015, 0, 0, 0, 0, 'Argus... what could have been...', 27980), -- Antorus, the Burning Throne: The Death of a Titan
(47287, 0, 0, 0, 0, 'Have you linked Light\'s Judgment into the Vindicaar Matrix Core?', 27980), -- The Vindicaar Matrix Core
(49143, 1, 0, 0, 0, 'Though Xe\'ra is gone, her essence can still aid us in our struggle.', 0), -- Essence of the Light Mother
(47652, 0, 0, 0, 0, 'Light Mother... you must have survived...', 27980), -- The Light Mother
(47508, 0, 669, 0, 0, 'Those bats are always a nuisance to deal with. This method will be more... efficient, I believe.', 27980), -- Fire At Will
(46213, 669, 0, 0, 0, 'I hope you brought backup with you.', 0), -- Legionfall: Emberfire
(48500, 0, 0, 0, 0, 'Light guide your path.', 27980), -- A Moment of Respite
(47627, 0, 0, 0, 0, 'Until their weapon is no longer a threat, we are cornered here like vermin.', 27980), -- Vengeance
(48513, 0, 1, 0, 0, 'The offensive continues.', 27980), -- Invasion Point Offensive
(45861, 0, 0, 0, 0, 'Are you ready?', 27980), -- A Gift From the Six
(45126, 0, 0, 0, 0, 'Save... yourself...', 27980), -- Unlikely Seduction
(45916, 0, 0, 0, 0, 'Keep these imps off me!', 27980), -- The Acolyte Imperiled
(45192, 0, 1, 0, 0, 'We must not hesitate!', 27980), -- Runes of Rending
(45187, 6, 6, 0, 0, 'Any leads, $n?', 27980), -- Secrets in the Underbelly
(45185, 6, 6, 0, 0, 'Have you found something?', 27980), -- Message from the Shadows
(45524, 0, 1, 0, 0, 'Let us go to Vrekt.', 27980), -- The Forgotten Heir
(46501, 0, 0, 0, 0, 'I\'m always lookin\' for more treasure!', 27980), -- Grave Robbin'
(46499, 0, 0, 0, 0, 'I\'m always lookin\' for more treasure!', 27980), -- Spiders, Huh?
(46247, 0, 603, 0, 0, 'Victory is nearly within our grasp. We cannot allow it to slip through our fingers!', 27980), -- Defending Broken Isles
(46245, 0, 0, 0, 0, 'Oi! Which building should we work on?$b$bI\'ve got deadlines to meet, mate!', 27980), -- Begin Construction
(46286, 0, 0, 0, 0, 'Crikey! Did you bring me Legionfall War Supplies?', 27980), -- Legionfall Supplies
(46805, 0, 0, 0, 0, 'Give no quarter. The Deceiver must fall.', 27980), -- The Deceiver's Downfall
(46253, 0, 396, 0, 0, 'The Legion\'s invasion must be ended.', 27980), -- Pillars of Creation
(46765, 0, 0, 0, 0, 'Found something?', 27980), -- The Broken Shore: Investigating the Legion
(47330, 0, 0, 0, 0, 'Yes, $n? What news do you bring?', 27980); -- Whispers of a Frightened World

INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(41207, 0, 0, 0, 0, 'Have you brought the supplies we requested?', 0), -- Supplies Needed: Leystone
(42959, 0, 0, 0, 0, 'Have you found anything special for Ari yet?', 0), -- Three Is a Lucky Number
(42940, 0, 1, 0, 0, 'Have your champions found a way to gain access to the Oculus yet?', 27980), -- When There's a Will, There's a Way
(42707, 1, 0, 0, 0, 'Have you obtained a vial of arcane water yet?', 0), -- A Magical Affliction
(44563, 0, 0, 0, 0, 'There is much to be done.', 27980), -- Redemption for the Fallen
(45316, 0, 0, 0, 0, 'Now is the time for action!', 27980), -- Stabilizing Suramar
(44754, 0, 0, 0, 0, '<Vanthir shudders violently and stares blankly ahead. He does not seem to be aware of your presence.>', 0), -- Waxing Crescent
(44723, 0, 0, 0, 0, 'Did you find more like me?', 27980), -- More Like Me
(44724, 0, 0, 0, 0, 'Have you learned where the captives have been taken?', 27980), -- Missing Persons
(44955, 0, 1, 0, 0, 'What have you learned?', 27980), -- Visitor in Shal'Aran
(38695, 0, 0, 0, 0, 'Elisande... how could you?', 27980), -- Crackdown
(39781, 0, 0, 0, 0, 'The war continues.', 0), -- Neltharion's Lair
(45175, 0, 25, 0, 0, 'Without the soul fragments we are lost!', 27980), -- Soul Prism of the Illidari
(44481, 0, 0, 0, 0, 'When the vessel is prepared, we will seek out his soul.', 27980), -- Destiny Unfulfilled
(44480, 0, 0, 0, 0, 'The vessel is nearly ready to take on the soul.', 27980), -- In My Father's House
(44414, 0, 0, 0, 0, 'A dreadlord poses little danger to you, eh?', 27980), -- Felspawns of Lothros
(44466, 0, 0, 0, 0, 'You mustn\'t lose hope.', 27980), -- An Unclear Path
(44464, 0, 0, 0, 0, 'When our work is complete, I will be lost to the Great Dark.', 27980), -- Awakenings
(38949, 0, 0, 0, 0, 'You\'re pretty lucky to have found me.', 0), -- So You Think You Can Sew
(38948, 0, 0, 0, 0, 'What\'ve you got in your hands, there?', 27980), -- Hard Times
(38947, 0, 0, 0, 0, 'They are quite remarkable creatures, really. I used to keep one as a pet and mount... but that was a lifetime ago.', 27980), -- Runic Catgut
(41499, 0, 0, 0, 0, 'I cannot think of a worse fate than to be controlled by another.', 27980), -- Squid Out of Water
(41001, 0, 0, 0, 0, 'We must defeat the Sashj\'tar once and for all.', 27980), -- Shatter the Sashj'tar
(40336, 0, 0, 0, 0, 'We finally have the advantage against the Sashj\'tar.$B$BNow is the time to kill the Tidemistress.', 27980), -- Turning the Tidemistress
(41709, 0, 0, 0, 0, 'The Tidemistress is a dangerous foe. We must be just as cunning to defeat her.', 0), -- Breaking Down the Big Guns
(40364, 0, 0, 0, 0, 'Move quickly, $c! These sea giants have an insatiable appetite!', 27980), -- Bubble Trouble
(41618, 0, 0, 0, 0, 'Have you slain the Seawarden?', 27980), -- The Seawarden
(41410, 0, 0, 0, 0, 'Move quickly, $n.', 27980), -- Dry Powder
(40334, 0, 0, 0, 0, 'I will help you collect what we need.', 0), -- Fisherman's Tonic
(40332, 0, 0, 0, 0, 'Throndyr deserved a more honorable death.', 0), -- Beach Bonfire
(40331, 0, 0, 0, 0, 'We will slay them all!', 27980), -- Bite of the Sashj'tar
(40320, 0, 0, 0, 0, 'I must know what has befallen my kin.', 27980), -- Band of Blood Brothers
(42955, 0, 0, 0, 0, 'Have you found enough nightwell energy yet?', 0), -- The Proper Way of Things
(43569, 0, 0, 0, 0, 'Where is Arluin?', 27980), -- Arluin's Request
(41231, 0, 6, 0, 0, 'Did you find the alpha?', 27980), -- Apex Predator
(41258, 0, 11, 0, 0, 'Daglir will be ruined after this.', 27980), -- Fruit of the Doom
(43994, 0, 0, 0, 0, '<Thalyssra is shaking uncontrollably and can barely speak.>', 0), -- Feed Thalyssra
(43564, 0, 0, 0, 0, '', 27980), -- Flow Control
(43563, 0, 0, 0, 0, 'Without those plates, the E.M.P. would rip itself apart in seconds.', 27980), -- Ephemeral Manastorm Projector
(43587, 0, 0, 0, 0, '<The leyline feed pulses softly.>', 0), -- Leyline Feed: Elor'shan
(43588, 0, 0, 0, 0, '<The leyline feed pulses softly.>', 27980), -- Leyline Feed: Kel'balor
(43562, 0, 0, 0, 0, 'We must activate all of the leyline feeds in Suramar before attempting the spell.', 27980), -- Giving It All We've Got
(43362, 0, 0, 0, 0, 'Do you have it?', 0), -- The Stuff of Dreams
(43361, 0, 0, 0, 0, 'Do you have the shards?', 0), -- Fragments of Disaster
(42491, 0, 0, 0, 0, 'Did you find it?', 27980), -- Long Buried Knowledge
(43314, 0, 0, 0, 0, 'Is it done?', 27980), -- Beware the Fury of a Patient Elf
(42490, 0, 0, 0, 0, 'Is it done?', 27980), -- Opening the Arcway
(44562, 0, 0, 0, 0, 'Have you felt it? Change is on the wind.', 27980), -- Growing Strong
(43318, 0, 0, 0, 0, 'I know you will defend my honor, $n.', 27980), -- Ly'leth's Champion
(43813, 0, 0, 0, 0, '<The beacon is cold and dark.>', 0), -- Sanctum of Order Teleporter Online!
(43317, 0, 0, 0, 0, 'I am prepared. It is nearly time.', 27980), -- In the Bag
(43315, 0, 0, 0, 0, 'Is it done?', 27980), -- Death Becomes Him
(43312, 0, 0, 0, 0, 'Did you find my son?', 27980), -- Thinly Veiled Threats
(43311, 0, 0, 0, 0, 'Yes, I know why you are here. Yes, I can get the jobe done. No, it will not be free.', 27980), -- Or Against Us
(43352, 0, 0, 0, 0, 'Did you deter them yet?', 27980), -- Asset Security
(42841, 0, 0, 0, 0, 'Where\'s my cut?', 27980), -- A Big Score
(42840, 0, 0, 0, 0, 'My price will not change. Do we have a deal?', 27980), -- If Words Don't Work...
(43969, 0, 0, 0, 0, 'Best not to lurk if you aren\'t doing business.', 27980), -- Hired Help
(42835, 0, 1, 0, 0, 'Having fun?', 27980), -- The Old Fashioned Way
(42834, 0, 0, 0, 0, 'Having trouble?', 27980), -- Intense Concentration
(42832, 0, 0, 0, 0, 'Enjoying yourself?', 27980), -- The Fruit of Our Efforts
(42489, 0, 0, 0, 0, 'What did you find?', 0), -- Thalyssra's Drawers
(41230, 6, 6, 0, 0, 'Do you have the snares, $r?', 27980), -- Trapping Evolved
(41215, 0, 1, 0, 0, 'With the number of trappers thinned, their ability to scout into Suramar will be sorely hampered.', 27980), -- They Become The Hunted
(40617, 603, 603, 0, 0, 'You must find Nighteyes!', 27980), -- Turn Around, Nighteyes
(41256, 603, 603, 0, 0, 'Daglir is young and foolish!', 27980), -- Blast of Spice Fish
(41107, 1, 1, 0, 0, 'I would avoid eating any food until you\'ve washed your hands.', 27980), -- Bad Apples
(41915, 6, 0, 0, 0, 'Where is the master?', 0), -- The Master's Legacy
(43811, 0, 0, 0, 0, '<The beacon is cold and dark.>', 0), -- Lunastre Estate Teleporter Online!
(41466, 1, 1, 0, 0, 'He was so passionate, so driven. I saw his vision, created it to his exact specifications. Beautiful filigree and enamel put to a fearsome weapon...', 27980), -- Estate Jewelry: Haute Claw-ture
(41465, 1, 1, 0, 0, 'That oaf will undo years of hard work. It is so much easier to fall than it is to climb...', 27980), -- Estate Jewelry: A Braggart's Brooch
(42521, 0, 0, 0, 0, 'Were you able to locate Millhouse?', 0), -- The Enemy of My Enemy...
(42488, 0, 0, 0, 0, 'Did you find it?', 27980), -- Thalyssra's Abode
(40642, 6, 6, 0, 0, 'Do you have the essence? I must have it!', 27980), -- Power! Get The Power!
(40919, 6, 6, 0, 0, 'Have you obtained the hides?', 27980), -- Fel Bent for Leather
(40713, 5, 5, 0, 0, 'The tome! Do you have it?', 27980), -- The Black Tome
(40657, 6, 6, 0, 0, 'I can practically feel the buildings hum with power.', 27980), -- The Road to Fel
(40683, 1, 1, 0, 0, 'I hope you brought enough. I will require more energy before my studies are complete.', 27980), -- Discovery Requires Experimentation
(40625, 6, 6, 0, 0, 'Did you find anything? I did not exactly get a chance to pack my things before I was exiled.', 27980), -- A Different Source
(41097, 0, 0, 0, 0, '<The Shard of Vargos pulses in your hand.>', 0), -- Shard of Vorgos
(41098, 0, 0, 0, 0, '<The Shard of Kozak tugs as if it wants to fly into place.>', 0), -- Shard of Kozak
(41214, 0, 0, 0, 0, 'Aye, is that all of him? We aren\'t missing any parts are we?', 27980), -- Parts 0
(41222, 0, 0, 0, 0, 'We\'ve got to get to the felstalker pits an\' save Brambley!', 27980), -- Into The Pit!
(43594, 0, 0, 0, 0, '<The leyline feed pulses softly.>', 0), -- Leyline Feed: Halls of the Eclipse
(41140, 0, 0, 0, 0, 'Have you found the key yet?', 27980), -- Search and Rescue!
(41139, 0, 0, 0, 0, 'Did ye find the key?', 27980), -- The Key Is Around Here Somewhere...
(40929, 0, 0, 0, 0, 'Do you have the Legion Emblems?', 27980), -- Symbols of Power
(40328, 0, 0, 0, 0, 'Have the soul engine cages been opened?', 27980), -- A Fate Worse Than Dying
(40901, 0, 0, 0, 0, 'What news do you bring of Grimwing the Devourer?', 0), -- Grimwing the Devourer
(40898, 0, 0, 0, 0, 'Do you have the Fresh Fel-Flesh I require?', 27980), -- Fresh Meat
(40307, 0, 0, 0, 0, 'Do you have my glaives, $r?', 27980), -- Glaive Circumstances
(41575, 0, 0, 0, 0, '<The beacon is cold and dark.>', 0), -- Felsoul Teleporter Online!
(40469, 6, 0, 0, 0, 'Did you find the smuggler? What did they say?', 0), -- Final Preparations
(40370, 0, 6, 0, 0, 'Did you find the source of the corruption?', 27980), -- Purge the Unclean
(40348, 0, 6, 0, 0, 'Is it done?', 27980), -- Something in the Water
(40368, 1, 1, 0, 0, 'Remember, the scales need to be whole to be of any use as a focus.', 27980), -- Turtle Powered
(43591, 0, 0, 0, 0, '<The leyline feed crackles as wild energy escapes the gaps in the column.>', 27980), -- Leyline Feed: Ley Station Aethenar
(43592, 0, 0, 0, 0, '<The leyline feed pulses softly.>', 0), -- Leyline Feed: Falanaar Arcway
(43593, 0, 0, 0, 0, '<The leyline feed pulses softly.>', 0), -- Leyline Feed: Falanaar Depths
(42722, 0, 0, 0, 0, 'Did you let them out?', 27980), -- Friends in Cages
(40947, 0, 0, 0, 0, 'Were you successful?', 0), -- Special Delivery
(40730, 603, 603, 200, 200, 'Did you find enough?', 27980), -- Redistribution
(41148, 1, 1, 0, 0, 'Have you served those who suffer?', 27980), -- Dispensing Compassion
(41320, 6, 6, 0, 0, 'Do you have my necklaces? They are of no use to me on the necks of those... creatures.', 27980), -- Pry It From Their Cold, Feral Claws
(41307, 6, 6, 0, 0, 'Can you imagine, a Lespin original hiding under a pile of leaves? What a waste.', 27980), -- All That Glitters
(41123, 6, 6, 0, 0, 'Do you have it?', 27980), -- An Artisan's Mark
(45056, 0, 1, 0, 0, 'You must find her!', 27980), -- Noressa
(41494, 0, 0, 0, 0, 'You witness history, $r.', 27980), -- Eminent Grow-main
(41485, 0, 0, 0, 0, 'Have you freed them, $r?', 27980), -- Moonwhisper Rescue
(41480, 0, 0, 0, 0, 'Managazer must perish, $r.', 27980), -- Managazer
(41479, 0, 0, 0, 0, 'Have you finished?', 27980), -- Natural Adversaries
(41475, 0, 0, 0, 0, 'Are you being gentle with your pruning?', 27980), -- Prongs and Fangs
(41474, 0, 0, 0, 0, 'How goes the planting?', 27980), -- Fertilizing the Future
(41197, 0, 0, 0, 0, 'Have you managed to rescue any?', 27980), -- You've Got to Be Kitten Me Right Meow
(44561, 0, 0, 0, 0, 'The arcan\'dor needs time.', 27980), -- Seed of Hope
(42225, 0, 0, 0, 0, '', 27980), -- Breaking the Seal
(41453, 0, 0, 0, 0, 'Did you bring the little one back with you?', 27980), -- Homeward Bounding
(41452, 0, 0, 0, 0, 'Is everything in its proper place?', 27980), -- Feline Frantic
(43590, 0, 0, 0, 0, '<The feed pulses softly.>', 27980), -- Leyline Feed: Ley Station Moonfall
(40324, 0, 0, 0, 0, 'Feed Theryn as much as he will take.', 27980), -- Arcane Communion
(40970, 0, 0, 0, 0, 'Is it done?', 0), -- The Orchestrator of Our Demise
(41032, 0, 0, 0, 0, 'I can still sense them, $n.', 27980), -- Stop the Spell Seekers
(40965, 0, 0, 0, 0, 'How fares the education?', 27980), -- Lay Waste, Lay Mines
(40967, 0, 0, 0, 0, 'Did you locate them?', 27980), -- Precious Little Left
(41030, 0, 0, 0, 0, 'What is this?', 0), -- Sigil Reclamation
(43808, 0, 0, 0, 0, '<The beacon is cold and dark.>', 0), -- Moon Guard Teleporter Online!
(40321, 0, 1, 0, 0, 'It will take time, but Tel\'anor will flourish again. I swear it on my life.', 27980), -- Feathersong's Redemption
(40319, 1, 1, 0, 0, 'What was that? I heard a familiar voice... it couldn\'t be.', 27980), -- The Final Ingredient
(40315, 0, 1, 0, 0, 'Please let me fulfill my wishes, $n.', 27980), -- End of the Line
(40306, 6, 0, 0, 0, 'Do you have the tome, $r?', 0), -- The Last Chapter
(40308, 6, 0, 0, 0, 'What do you have there?', 0), -- Fragments of Memory
(40300, 6, 0, 0, 0, 'Did you find anything?', 0), -- Tools of the Trade
(40744, 6, 0, 0, 0, 'Do you have what I require, $r? We don\'t have much time to spare.', 0), -- An Ancient Recipe
(40266, 0, 0, 0, 0, '<Thaedris seems lost in thought as he gazes towards the city of Suramar.>', 0), -- The Lost Advisor
(43809, 0, 0, 0, 0, '<The beacon is cold and dark.>', 0), -- Tel'anor'eporter Online!
(41028, 0, 0, 0, 0, '', 27980), -- Power Grid
(43106, 0, 0, 0, 0, '<Oculeth mumbles incoherently under his breath.>', 0), -- Feed Oculeth
(40747, 0, 0, 0, 0, 'Salvaging the equipment here is necessary if I am to develop a teleporter network for Thalyssra.', 27980), -- The Delicate Art of Telemancy
(40798, 0, 0, 0, 0, '<Noressa eyes you suspiciously.>', 0), -- Cling to Hope
(42147, 0, 0, 0, 0, 'Have you made contact with our sympathizers?', 0), -- First Contact
(42079, 0, 0, 0, 0, 'Not to worry, it will not hurt $Ghim:her;.', 27980), -- Masquerade
(41989, 0, 0, 0, 0, 'Anarys could halt our efforts before they begin.', 27980), -- Blood of My Blood
(41834, 0, 0, 0, 0, 'Pleased to make your acquaintance.', 27980), -- The Masks We Wear
(41760, 0, 0, 0, 0, 'We will need more subjects if we are to continue Kel\'danath\'s research.', 27980), -- Kel'danath's Legacy
(41702, 0, 0, 0, 0, '<This withered seems entranced by the spellstone. He is completely pacified.>', 0), -- Written in Stone
(40796, 0, 0, 0, 0, 'Can you help me? Is there nothing you can do?', 27980), -- Lingering on the Edge
(44672, 0, 0, 0, 0, 'We need all the ancient mana we can get. Make sure you know how to find it!', 27980), -- Ancient Mana
(40009, 0, 0, 0, 0, '<Thalyssra\'s eyes have dulled and her body is shaking uncontrollably.>', 27980), -- Arcane Thirst
(44448, 0, 0, 0, 0, 'Any news?', 27980), -- In the House of Light and Shadow
(44153, 0, 0, 0, 0, 'This is where you must place Light\'s Heart.', 0), -- Light's Charge
(43705, 0, 0, 0, 0, 'The Legion must fall!', 27980), -- Nobundo's Last Stand
(44009, 0, 0, 0, 0, 'Show me what you\'ve found.', 0), -- A Falling Star
(48376, 0, 0, 0, 0, 'Oh ho, whatcha got there? Primal Sargerite? Sounds fancy!$b$bI bet if we mash some \'o that stuff with Obliterum, we can make it beefier! Give it more of a punch when you apply it to yer armor.$b$bHeck, I bet if we smash a bunch of it together at once, we can make a whole batch \'o the stuff! Whaddya say, wanna give it a try?', 0), -- Mass Primal Obliterum
(48375, 0, 0, 0, 0, 'Oh ho, whatcha got there? Primal Sargerite? Sounds fancy!$b$bI bet if we mash some \'o that stuff with Obliterum, we can make it beefier! Give it more of a punch when you apply it to yer armor.$b$bWhaddya say, want ta give it a try?', 0), -- Primal Obliterum
(42483, 0, 0, 0, 0, 'Hmm...', 0), -- Put It All on Red
(39786, 0, 0, 0, 0, 'Did you take him out?', 27980), -- A Stone Cold Gamble
(39792, 0, 0, 0, 0, 'Aint nothin like some good old meaty musken ribs, eh pal?', 27980), -- A Stack of Racks
(42447, 0, 0, 0, 0, '', 27980), -- Dances With Ravenbears
(42445, 0, 0, 0, 0, 'Ca-caw?', 0), -- Nithogg's Tribute
(42446, 0, 0, 0, 0, '', 27980), -- Singed Feathers
(40120, 0, 0, 0, 0, 'Have you done this task?', 27980), -- A Murky Fate
(42645, 0, 0, 0, 0, '', 27980), -- Spilling Bad Blood
(42641, 0, 0, 0, 0, '', 27980), -- What the Bonespeakers Buried
(42640, 0, 0, 0, 0, 'What\'s this?', 0), -- The Value of Knowledge
(42639, 0, 0, 0, 0, 'We will need the amulet\'s protection to proceed.', 27980), -- A Stone of Blood
(42635, 0, 0, 0, 0, 'How goes the hunt for knowledge?', 27980), -- The Mystery of Dreyrgrot
(39405, 0, 0, 0, 0, 'This appears to be the last verse.', 0), -- Stories of Battle
(40005, 0, 0, 0, 0, '', 27980), -- Stormheim's Salvation
(40002, 0, 0, 0, 0, 'The jailer has... the key...', 27980), -- A Familiar Fate
(39061, 0, 0, 0, 0, 'What have you found?', 27980), -- Whispers from the Dark
(39060, 0, 0, 0, 0, 'Have the caches been taken care of?', 27980), -- Combustible Contagion
(40078, 0, 0, 0, 0, '', 27980), -- A Heavy Burden
(39853, 0, 0, 0, 0, 'Together, we can defeat this foe!', 27980), -- Victory is Eternal
(39851, 0, 0, 0, 0, 'Once unbound, my Valkyra will throttle these wretched minions.', 27980), -- Allies in Death
(39850, 0, 0, 0, 0, 'Have you recovered your power?', 27980), -- Sundered
(39849, 0, 0, 0, 0, 'Were you able to secure the lantern?', 27980), -- To Light the Way
(39848, 0, 0, 0, 0, '<The air hangs silent as you approach.>', 27980), -- A Desperate Bargain
(38347, 0, 0, 0, 0, 'Gods, what is that stench?! $B$BThis disguise had better work!', 27980), -- Stealth by Seaweed
(38324, 0, 0, 0, 0, 'Make sure ye\'ve got enough bones before we move on.', 27980), -- Accessories of the Cursed
(38339, 0, 0, 0, 0, 'Do ye have enough for a proper disguise?', 27980), -- A Little Kelp From My Foes
(38817, 0, 0, 0, 0, 'Were you able to recover her remains?', 0), -- Regal Remains
(38808, 0, 0, 0, 0, 'How went the hunt, outsider?', 27980), -- Bjornharta
(38810, 0, 0, 0, 0, 'What do you bring?', 27980), -- The Dreaming Fungus
(39788, 0, 0, 0, 0, 'Has the corruption been removed?', 27980), -- The Runewood's Revenge
(38778, 0, 0, 0, 0, 'My shackles remain...', 27980), -- Turn the Keys
(43596, 0, 0, 0, 0, 'Is it done?', 27980), -- Piercing the Mists
(40044, 0, 0, 0, 0, '', 27980), -- Shadows in the Mists
(43595, 0, 0, 0, 0, 'Do you have the blades?', 27980), -- To Honor the Fallen
(40046, 0, 0, 0, 0, 'Have you found answers, or more questions?', 27980), -- Scavenging the Shallows
(44721, 0, 0, 0, 0, 'What is Helya planning?', 27980), -- Helya's Conquest
(44771, 0, 0, 0, 0, 'I\'ve told you my tale, but did you bring the grog?', 27980), -- A Threat Rises
(39804, 0, 0, 0, 0, '', 27980), -- Speaking of Bones
(39787, 0, 0, 0, 0, 'You got my trophy yet?', 27980), -- Rigging the Wager
(39793, 0, 0, 0, 0, 'Make sure to get the good stuff!', 27980), -- Only the Finest
(38342, 0, 0, 0, 0, 'Well, we made it this far...', 27980), -- Another Way
(38405, 0, 0, 0, 0, 'Did you find everything?', 0), -- To Weather the Storm
(39593, 0, 0, 0, 0, 'Have you managed to find them all?', 27980), -- The Shattered Watcher
(39592, 0, 0, 0, 0, '', 27980), -- A Trial of Will
(39591, 0, 0, 0, 0, '', 27980), -- A Trial of Valor
(39595, 0, 0, 0, 0, 'What is this you bring?$B$BYou honor me, outsider.', 27980), -- Blood and Gold
(39590, 0, 0, 0, 0, 'An ironic gift you bring me, challenger.', 27980), -- Ahead of the Game
(38558, 0, 0, 0, 0, 'Did you find the oscillator?', 27980), -- See Ya Later, Oscillator
(38053, 0, 0, 0, 0, 'I cannot build a new transponder without that battery!', 27980), -- Assault and Battery
(38036, 0, 0, 0, 0, 'Did you find anything?', 27980), -- Supplies From the Skies
(38052, 0, 0, 0, 0, 'There will be no peace with those monsters running free.', 27980), -- Boarded!
(38035, 0, 0, 0, 0, 'Can we count on you?', 27980), -- A Royal Summons
(41778, 0, 0, 0, 0, 'What are the results, $n?', 0), -- Fire it Up
(39986, 0, 0, 0, 0, 'Go ahead and take a look.', 27980), -- Magic Message
(40991, 0, 0, 0, 0, 'Mackerel may not be extravagant, but it will fill your belly.', 27980), -- Opening the Test Kitchen
(44055, 0, 0, 0, 0, 'I do not need my eyes to see the value you bring to this war.', 27980), -- They Have A Pitlord
(39772, 0, 0, 0, 0, 'Have you found my skull?', 0), -- Can't Hold a Candle To You
(40345, 0, 0, 0, 0, 'You come in when jobs are done.', 27980), -- Burn the Candle at Both Ends
(40339, 0, 0, 0, 0, 'What you lookin\' at, stink head?', 27980), -- Candle of Command
(39768, 0, 0, 0, 0, 'We once thought they were nothing but overgrown rats, but they do have some intelligence.', 27980), -- Candle to the Grave
(39765, 0, 0, 0, 0, 'The desecration...', 27980), -- Wax On, Wax Off
(39656, 0, 0, 0, 0, 'The critter hand cannon is loaded and ready for use! Just aim for one of the packs nearby. The packleaders should be easy to kill once the howlers are distracted.', 27980), -- Wolf Pack Attack
(40000, 0, 0, 0, 0, 'You can\'t be huntin\' hawks if you\'re here chattin\' at me.', 27980), -- A True Hunter
(39670, 0, 0, 0, 0, 'Have you snatched the rabbits yet?', 27980), -- Critter Scatter Shot
(40594, 0, 0, 0, 0, 'The drogbar sure do love those rocks.', 27980), -- Justice Rains from Above
(42088, 0, 0, 0, 0, 'I knew we should have secured this town better.', 27980), -- Evacuate Snowmane
(39777, 0, 0, 0, 0, 'We need all the time you can buy us.', 27980), -- Buy Us Time
(39862, 0, 0, 0, 0, 'Siegbrul Olgrul torments all who serve him. There are evil drogbar, and then there is this foul monster.', 27980), -- The Siegebrul
(39776, 0, 0, 0, 0, 'Worms. Why did it have to be worms? I hate worms.', 27980), -- Battle Worms
(42630, 0, 0, 0, 0, 'Let\'s show those harpies why they shouldn\'t even think about attacking Thunder Totem!', 27980), -- Bolas Bastion
(39867, 0, 0, 0, 0, 'I\'ll have the last laugh when Hemet sees proof that this magical lion exists!', 27980), -- I'm Not Lion!
(39178, 0, 0, 0, 0, 'I\'m looking forward to hanging the antlers of an ancient spirit within the walls of the hunters\' lodge!', 27980), -- Moose on the Loose
(40228, 0, 1, 0, 0, 'Don\'t just stand there, head out into the basin and find that bird!', 27980), -- Scout It Out
(40216, 0, 1, 0, 0, 'Keep an eye on the gnome while you\'re huntin\'. She\'s never held a rifle before.', 27980), -- A Hunter at Heart
(39392, 1, 1, 0, 0, 'Procuring a few Bristlefur Pelts should help sell me on your huntin\' skills.', 27980), -- Bear Huntin'
(39124, 0, 1, 0, 0, 'Ya can\'t be huntin\' Elderhorn if you\'re lingerin\' around camp.', 27980), -- Moose Shootin'
(39123, 0, 0, 0, 0, 'Anyone worthy of huntin\' in these hills should be able to take down a few stalkers.', 27980), -- Lion Stalkin'
(39859, 1, 0, 0, 0, 'I\'ve been waitin\' all day for Addie to finish her first draft.$b$bHow hard can it be to write a few words about the greatest hunter who\'s ever lived?', 0), -- Note-Eating Goats
(40170, 0, 1, 0, 0, 'Have those amateur hunters scattered? Don\'t be afraid to use your fists if words don\'t do the job.', 27980), -- Amateur Hour
(40230, 0, 0, 0, 0, 'Clawdayshus is ruthless. Murky must stop him.', 27980), -- Oh, the Clawdacity!
(40102, 0, 0, 0, 0, 'These young murlocs show such promise. They\'ll do this shore good.', 27980), -- Murlocs: The Next Generation
(40049, 0, 0, 0, 0, 'Am I mistaken in thinking you can swim? There\'s a spell for that.', 27980), -- Slime Time
(40047, 0, 0, 0, 0, 'Pufferfish have this impressive ability of... exploding. They could be a powerful tool for Murky.', 27980), -- I'll Huff, I'll Puff...
(40045, 0, 0, 0, 0, 'Getting the support of the tadpoles is very important for our mission.', 27980), -- Nature vs. Nurture
(39439, 0, 0, 0, 0, 'We have possessed these relics for generations until the murlocs put their fishy flippers on them.', 27980), -- Stonedark Relics
(39437, 0, 0, 0, 0, 'Slippery little critters, aren\'t they?', 27980), -- Deep in the Cavern
(39438, 0, 0, 0, 0, 'Can you pronounce murloc names? I never can.', 27980), -- Guhruhlruhlruh
(39440, 0, 0, 0, 0, 'Those arms fallin\' off?', 27980), -- You Lift, Brul?
(39426, 0, 0, 0, 0, 'Drogbar are not violent by nature, despite our size. But the Bloodtotem crossed us, and they pay the debt in blood.', 27980), -- Blood Debt
(39588, 0, 0, 0, 0, 'These tauren have always been bloodthirsty. The Highmountain chieftain has barely been able to stop them killing all of us.', 27980), -- They Will Pay With Blood
(39425, 0, 0, 0, 0, 'I have power over the earth without my crystal, but my power is much greater with it than without.', 27980), -- Stonedark Crystal
(39391, 0, 0, 0, 0, 'These beasts are not terribly bright, but they are loyal in their way.', 27980), -- Pet Rocks
(39374, 0, 0, 0, 0, 'I just hope the Bloodtotem don\'t cut us down for demanding their chieftain\'s time.', 27980), -- An Audience with Torok
(39373, 0, 0, 0, 0, 'Your size belies your strength, $n.', 27980), -- Hags of a Feather
(39372, 0, 0, 0, 0, 'The harpies moved after the drogbar attacked much of Highmountain. They saw an opportunity and ceased upon it.', 27980), -- Witch of the Wood
(39774, 0, 0, 0, 0, 'You must weaken the demons so I am able to trap them.', 27980); -- Demon Detainment

INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(39764, 0, 0, 0, 0, 'Have you recovered the soul chambers yet?', 27980), -- Shiny, But Deadly
(39429, 0, 0, 0, 0, 'It has been many years since we have had to enter the Haglands in force.', 27980), -- Assaulting the Haglands
(39321, 0, 0, 0, 0, 'Many Skyhorn have fallen to the witchcraft of these hags.', 27980), -- The Three
(44207, 0, 0, 0, 0, 'Place a work order for Champion armaments and equipment.', 27980), -- Portal Full of Shiny Things
(39318, 0, 0, 0, 0, 'These harpies are all over the place!', 27980), -- Nursing the Wounds
(39419, 0, 1, 0, 0, 'Hexweaver Akara must be slain if the Skyhorn wish to gain the upper hand.', 27980), -- Hex-a-Gone
(42622, 0, 0, 0, 0, 'Can you feel the beat?', 27980), -- Ceremonial Drums
(39133, 0, 0, 0, 0, 'We will all be honorary masons if this keeps up much longer.', 27980), -- No Time to Talk
(39134, 0, 0, 0, 0, 'Dargrul always was a vile creature. I never realized to what extent until he got his hands on that hammer.', 27980), -- Wrathshard
(42596, 0, 0, 0, 0, 'The moose are already broken. Just hop in the saddle and you can bring them here to me!', 27980), -- Mountainstrider Round-Up
(42590, 0, 0, 0, 0, 'Thank you for your kindness. Truly.', 27980), -- Moozy's Reunion
(40520, 0, 0, 0, 0, 'Earth, air, and water are all magics we have come to know well in our mountain.', 27980), -- To See the Past
(40167, 0, 0, 0, 0, 'The history of this place extends beyond our limited memory.', 27980), -- The Story of Huln
(39027, 0, 0, 0, 0, 'This is a hard day.', 27980), -- Dargrul and the Hammer
(39043, 0, 0, 0, 0, 'Highmountain stands!', 27980), -- Bitestone Enclave
(39487, 0, 0, 0, 0, 'The drogbar used to control only earthen magic, but it seems they\'ve found a way to draw power from other sources.', 27980), -- Crystal Fury
(39489, 0, 0, 0, 0, 'We must cleanse the cavern of the drogbar.', 27980), -- Invading Spelunkers
(39488, 0, 0, 0, 0, 'I believe the drogbar are learning stronger magic now that they have possession of the Hammer of Khaz\'goroth.', 27980), -- Balance of Elements
(39614, 0, 0, 0, 0, 'We used to supply the drogbar with most of their food between our fish and crops. What will the fools eat now?', 27980), -- Fish Out of Water
(39316, 0, 0, 0, 0, 'They slew many of my brothers and sisters, but at least some managed to escape. Others, however, we captured.', 27980), -- Trapped Tauren
(39277, 0, 0, 0, 0, 'For this group of drogbar to turn against us after so many years of peace...', 27980), -- Spray and Prey
(39491, 0, 0, 0, 0, 'The Rivermane are a peaceful tribe. We provide the others with food and healing in exchange for protection and equipment.\n\nWhen pressed, however, I am willing to put my magic to more violent use.', 27980), -- Ormgul the Pestilent
(39490, 0, 0, 0, 0, 'The drogbar have a mastery of the earth and creatures that dwell within it.', 27980), -- Infestation
(39272, 0, 0, 0, 0, 'The crops must be rid of this poison!', 27980), -- Poisoned Crops
(42424, 0, 0, 0, 0, 'Have your champions discovered anything of note about Archmage Vargoth?', 27980); -- Following In His Footsteps

DELETE FROM `quest_request_items` WHERE `ID` IN (51544 /*Disarming the Cannons*/, 51190 /*Granting a Reprieve*/, 51445 /*Thros, the Blighted Lands*/, 52149 /*Everburning*/, 52485 /*Hatred's Focus*/, 52484 /*Buried Power*/, 52483 /*Nightmare Catcher*/, 52482 /*The Old Bear*/, 50639 /*Waycrest Manor: The Fallen Mother*/, 52512 /*Fate's End*/, 52511 /*Opening the Way*/, 52510 /*Shrine of the Storm: The Missing Ritual*/, 52508 /*Ritual Effects*/, 53457 /*Quartermaster's Bounty*/, 53349 /*Conquest's Reward*/, 52445 /*Tol Dagor: The Fourth Key*/, 52253 /*The Keys to Success in Freehold*/, 52252 /*An Explosive Entrance*/, 52246 /*Lost Shipment*/, 50588 /*Storming the Manor*/, 50583 /*To the Other Side*/, 50584 /*Ruinous Rituals*/, 50585 /*Hexecutioner*/, 50453 /*Barrier Buster*/, 50455 /*Leaving the Nest*/, 50456 /*Hexed Hatchlings*/, 50454 /*A Traitor's Death*/, 51356 /*WANTED: Sister Lilias*/, 50960 /*Sweete's Orders*/, 50447 /*Remembering the Fallen*/, 50763 /*One Last Request*/, 50762 /*The Lady's Fate*/, 50761 /*Blood in the Chapel*/, 50759 /*Running Late*/, 50450 /*An Offensive Harvest*/, 50451 /*Eating Through the Defenses*/, 50446 /*Witchrending*/, 50253 /*An Improvised Arsenal*/, 50174 /*All Wrapped Up*/, 50175 /*An Eight-Legged Curse*/, 50152 /*Digging for Scraps*/, 50173 /*Precious Metals*/, 50151 /*A Steady Ballast*/, 50149 /*A Weather Eye*/, 50965 /*Those Who Remain*/, 50967 /*Lost in the Woods*/, 50970 /*A Farmer's Fate*/, 51001 /*Every Day I'm Smugglin'*/, 51018 /*Asking for a Friend*/, 50978 /*Out With the Old Boss*/, 51019 /*She's Got it Where it Counts*/, 52050 /*A More Challenging Career*/, 51020 /*Cutthroat Business Practices*/, 50481 /*In the Hall of the Drust King*/, 50329 /*Matrons of the Crimsonwood*/, 50445 /*Controlling the Situation*/, 50530 /*Witch Way Out?*/, 50325 /*Stopping the Grand Rite*/, 50306 /*Odds and Ends*/, 50265 /*Saving Master Ashton*/, 50036 /*A Weapon of Old*/, 50090 /*Building Defenses*/, 50092 /*Curiously Strong*/, 50903 /*A Missing Master*/, 51390 /*WANTED: The Crimson Cutthroats*/, 50238 /*Bramblethorn*/, 50001 /*Breaking Hag*/, 51472 /*Life Preserver*/, 50953 /*Greenstalker*/, 51543 /*Saplings in the Snow*/, 49730 /*WANTED: Thundersnout*/, 50418 /*Deadliest Cache: Sink and Swim*/, 50391 /*Deadliest Cache: Gun Fishin'*/, 49807 /*A New Order*/, 49803 /*Changing of the Guard*/, 49804 /*Sharp Thinking*/, 49443 /*A Lesson in Witch Hunting*/, 48946 /*The Order of Embers*/, 48944 /*Unlocking History*/, 48963 /*Diversionary Tactics*/, 51134 /*If Bones Could Talk*/, 48943 /*Salvage Rights*/, 48942 /*Yeti to Rumble*/, 52075 /*Boned*/, 48179 /*Rescue Rangers*/, 48183 /*The Hills Are Alive*/, 48182 /*Total Cairnage*/, 48475 /*Seeing Spirits*/, 48524 /*Culling the Coven*/, 48523 /*The Murderous Matron*/, 48520 /*The Three Sisters*/, 48519 /*Hope They Can't Swim*/, 49295 /*Clear-Cutting*/, 48518 /*Save Who We Can*/, 48883 /*Big Gulls Won't Die*/, 48882 /*I Like Fish Guts and I Cannot Lie*/, 48904 /*Take the Bait*/, 48880 /*Mean Gulls*/, 49242 /*Quill or Be Quilled*/, 48165 /*Harmful If Swallowed*/, 48170 /*Once Bitten, Twice Shy*/, 48113 /*A Pungent Solution*/, 48111 /*Trial by Superstition*/, 48110 /*In Case of Ambush*/, 48109 /*The Woods Have Eyes*/, 48283 /*Standing Accused*/, 47289 /*Teddies and Tea*/, 47950 /*Cured Ham*/, 47948 /*Pork Chop*/, 47947 /*Big Bad Wolves*/, 47946 /*Save Their Bacon*/, 48683 /*Changing Seasons*/, 48678 /*Questionable Offerings*/, 48805 /*Research Recovery*/, 48804 /*Mistakes Were Made*/, 48793 /*The Adventurer's Society*/, 47968 /*Signs and Portents*/, 51889 /*The Wrath of Grapes*/, 52837 /*Seal of Wartorn Fate: War Resources*/, 52835 /*Seal of Wartorn Fate: Marks of Honor*/, 52834 /*Seal of Wartorn Fate: Gold*/, 48768 /*Brined Justice*/, 48761 /*Spiderphobia*/, 48764 /*Don't Pick a Fight*/, 53035 /*A Shrouded Path Through Time*/, 49223 /*The Long Con*/, 53097 /*Despondent Ablutions*/, 50386 /*Flush Them Out*/, 50368 /*Terror of the Kraul*/, 50340 /*Steal Them Back*/, 50367 /*Anger in a Bottle*/, 50365 /*Run For the Hills*/, 50363 /*War Pigs*/, 50353 /*Boaring Company*/, 50088 /*Golden Fields Forever*/, 50069 /*Goldfield's War*/, 50065 /*A Reason to Stay*/, 50041 /*A Pocketful of Shells*/, 51314 /*Grain Drain*/, 49960 /*Sic 'Em!*/, 49886 /*Follow Your Nose*/, 50135 /*Stop Vining!*/, 50134 /*Gadgets and Gizmos Aplenty*/, 51209 /*Mighty Grokkfist*/, 51208 /*Wheat A Minute*/, 51504 /*Cookie Delivery*/, 51207 /*Ettin It Done*/, 51204 /*WANTED: Razorclaw Alpha*/, 51200 /*The Black Sheep*/, 51203 /*Cry Wolf*/, 51215 /*Milking Goats*/, 51492 /*Gunpowder Plot*/, 51251 /*Basement Dwellers*/, 50773 /*You're a Shark*/, 50698 /*Problem Solving with Gunpowder*/, 50679 /*Piercing the Shield*/, 50672 /*Any Ammo Will Do*/, 50653 /*Reclaiming our Defenses*/, 50644 /*Facing the Invaders*/, 50649 /*Filching from Thieves*/, 50645 /*Eeling in a Big One*/, 50621 /*Caught in the Net*/, 50616 /*A Bit of a Bind*/, 50614 /*Freedom for the Sea*/, 51386 /*Battle Victorious*/, 51220 /*Deep Sea Venture*/, 51545 /*Breaker Bad*/, 51427 /*I Like Turtles*/, 51540 /*Explosive Situation*/, 51221 /*Response Required*/, 51371 /*Flavorable Offering*/, 53476 /*The Great Sea Scrolls*/, 51343 /*Swimming Lessons*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(51544, 0, 0, 0, 0, 'What\'s the status of those cannons?', 28153), -- Disarming the Cannons
(51190, 0, 0, 0, 0, 'A bit of a breather. Let\'s hope it\'s enough.', 28153), -- Granting a Reprieve
(51445, 0, 1, 0, 0, 'I\'m with you, champion.', 28153), -- Thros, the Blighted Lands
(52149, 0, 0, 0, 0, 'Thank you.', 28153), -- Everburning
(52485, 0, 0, 0, 0, 'Have you found Korvash\'s bones?', 0), -- Hatred's Focus
(52484, 0, 0, 0, 0, 'What have you uncovered beneath the snows of Gol Osigr?', 0), -- Buried Power
(52483, 0, 0, 0, 0, 'Do you have the materials?', 0), -- Nightmare Catcher
(52482, 0, 0, 0, 0, 'Yes?', 28153), -- The Old Bear
(50639, 0, 0, 0, 0, 'This must be done.', 28153), -- Waycrest Manor: The Fallen Mother
(52512, 0, 1, 0, 0, 'By the Tides, I thought we were done for.', 28153), -- Fate's End
(52511, 0, 1, 0, 0, 'There we are. The clouds clear and the sea calms. Our way is open.', 28153), -- Opening the Way
(52510, 1, 0, 0, 0, 'Were you able to recover the Ritual of Safe Passage?', 0), -- Shrine of the Storm: The Missing Ritual
(52508, 1, 0, 0, 0, 'It warms my heart to see these used for good once more.', 0), -- Ritual Effects
(53457, 0, 0, 0, 0, 'To defeat the enemy, you will need to keep your equipment in peak condition. If you have been unable to acquire more powerful arms, I can requisition from the quartermaster on your behalf.', 0), -- Quartermaster's Bounty
(53349, 0, 0, 0, 0, '', 28153), -- Conquest's Reward
(52445, 1, 1, 0, 0, 'I knew securing that last key wouldn\'t be a problem for you, $n!', 28153), -- Tol Dagor: The Fourth Key
(52253, 1, 1, 0, 0, 'Nicely done! See? I knew those Irontide wouldn\'t be a problem for you.', 28153), -- The Keys to Success in Freehold
(52252, 1, 1, 0, 0, 'Nicely done! These are going to make quite an impact, if you\'ll forgive the pun.', 28153), -- An Explosive Entrance
(52246, 0, 1, 0, 0, 'Did you find what happened to Jaina?', 28153), -- Lost Shipment
(50588, 0, 0, 0, 0, '', 28153), -- Storming the Manor
(50583, 0, 0, 0, 0, 'What news of the other inquisitors?', 28153), -- To the Other Side
(50584, 0, 0, 0, 0, 'Have the monsters been abolished?', 28153), -- Ruinous Rituals
(50585, 0, 0, 0, 0, 'Yes, $c?', 28153), -- Hexecutioner
(50453, 0, 0, 0, 0, 'I don\'t think these guys will be needin\' this cannon anymore.', 0), -- Barrier Buster
(50455, 0, 0, 0, 0, 'Are they safe?', 28153), -- Leaving the Nest
(50456, 0, 0, 0, 0, 'Have you taken care of the charms?', 28153), -- Hexed Hatchlings
(50454, 0, 0, 0, 0, 'Is it done?', 28153), -- A Traitor's Death
(51356, 0, 0, 0, 0, 'Inquisitor?', 0), -- WANTED: Sister Lilias
(50960, 6, 0, 0, 0, 'What have you brought, mainlander?', 0), -- Sweete's Orders
(50447, 0, 0, 0, 0, 'What\'s this?', 0), -- Remembering the Fallen
(50763, 0, 0, 0, 0, 'What... what\'s this?', 0), -- One Last Request
(50762, 6, 0, 0, 0, 'What have you found?', 0), -- The Lady's Fate
(50761, 0, 5, 0, 0, 'We must rout these knaves!', 28153), -- Blood in the Chapel
(50759, 0, 0, 0, 0, 'It must be around here somewhere...', 0), -- Running Late
(50450, 0, 0, 0, 0, 'Did ya find any good ones?', 28153), -- An Offensive Harvest
(50451, 0, 0, 0, 0, 'How\'s the boar situation?', 28153), -- Eating Through the Defenses
(50446, 0, 0, 0, 0, 'Have you taken care of the Matrons?', 28153), -- Witchrending
(50253, 0, 0, 0, 0, 'What can ol\' Angus do fer ye?', 28153), -- An Improvised Arsenal
(50174, 0, 0, 0, 0, 'I can\'t imagine how scared those miners are...', 28153), -- All Wrapped Up
(50175, 0, 0, 0, 0, 'Are they all dead?', 28153), -- An Eight-Legged Curse
(50152, 0, 0, 0, 0, 'What did you find at the armory?', 0), -- Digging for Scraps
(50173, 0, 0, 0, 0, 'Did you have any luck with the mine?', 28153), -- Precious Metals
(50151, 0, 0, 0, 0, 'The blacksmith won\'t survive long with the coven hunting him down. \n\nI\'d recommend leaving posthaste.', 28153), -- A Steady Ballast
(50149, 0, 0, 0, 0, 'What news do you bring?', 28153), -- A Weather Eye
(50965, 0, 0, 0, 0, 'Is there something more you need?', 0), -- Those Who Remain
(50967, 0, 0, 0, 0, 'Is there any sign of her? She\'s a strong woman, but I worry for her fate.', 28153), -- Lost in the Woods
(50970, 0, 0, 0, 0, 'Did you finish your task?', 28153), -- A Farmer's Fate
(51001, 1, 0, 0, 0, 'You get the goods?', 0), -- Every Day I'm Smugglin'
(51018, 1, 1, 0, 0, 'Did you find something?', 28153), -- Asking for a Friend
(50978, 0, 1, 0, 0, 'Job done yet?', 28153), -- Out With the Old Boss
(51019, 0, 1, 0, 0, 'Job done?', 28153), -- She's Got it Where it Counts
(52050, 0, 0, 0, 0, 'The winds be fine for adventure!', 0), -- A More Challenging Career
(51020, 0, 1, 0, 0, 'There a vacancy in the Innkeeper position yet?', 28153), -- Cutthroat Business Practices
(50481, 0, 1, 0, 0, 'We must confront Gorak Tul.', 28153), -- In the Hall of the Drust King
(50329, 0, 1, 0, 0, 'Did you kill them?', 28153), -- Matrons of the Crimsonwood
(50445, 1, 1, 0, 0, 'Were you able to collect enough charms?', 28153), -- Controlling the Situation
(50530, 0, 1, 0, 0, 'How did you fare?', 28153), -- Witch Way Out?
(50325, 0, 1, 0, 0, 'Destroy the Ritual Foci.', 28153), -- Stopping the Grand Rite
(50306, 1, 1, 0, 0, 'Did you have any luck?', 28153), -- Odds and Ends
(50265, 0, 1, 0, 0, 'Master Ashton has suffered greatly at the hands of these monsters.', 28153), -- Saving Master Ashton
(50036, 0, 1, 0, 0, 'We\'d better get cooking!', 28153), -- A Weapon of Old
(50090, 0, 1, 0, 0, 'We\'ve pushed the front line out. That will give us some room.', 28153), -- Building Defenses
(50092, 0, 1, 0, 0, 'If we don\'t stop the fires, they could spread!', 28153), -- Curiously Strong
(50903, 0, 1, 0, 0, 'Oh! You\'re not one of those monsters at all. Did you trounce those brutes?', 28153), -- A Missing Master
(51390, 0, 0, 0, 0, 'The Crimson Cutthroats are a nasty bunch. I wouldn\'t be sad to see them go.', 28153), -- WANTED: The Crimson Cutthroats
(50238, 1, 1, 0, 0, 'Did you find Lord Sharptooth? I think one of the really big monsters has him.', 28153), -- Bramblethorn
(50001, 0, 1, 0, 0, 'We have a little breathing room.', 28153), -- Breaking Hag
(51472, 0, 1, 0, 0, 'Will you watch my back as I complete the ritual?', 28153), -- Life Preserver
(50953, 0, 1, 0, 0, 'Did you free Greenstalker\'s spirit?', 28153), -- Greenstalker
(51543, 1, 1, 0, 0, 'Did you find the mountain saplings I need?', 28153), -- Saplings in the Snow
(49730, 0, 0, 0, 0, 'Yes?', 0), -- WANTED: Thundersnout
(50418, 0, 0, 0, 0, 'Mph?', 28153), -- Deadliest Cache: Sink and Swim
(50391, 6, 6, 0, 0, 'Aye, $Glad:lass;?', 28153), -- Deadliest Cache: Gun Fishin'
(49807, 0, 0, 0, 0, 'You should be inducting them, not me!', 28153), -- A New Order
(49803, 0, 0, 0, 0, 'You will need to gather your recruits before we venture forth.', 28153), -- Changing of the Guard
(49804, 0, 0, 0, 0, 'I really hope this works...', 28153), -- Sharp Thinking
(49443, 0, 0, 0, 0, 'Did you find it?', 28153), -- A Lesson in Witch Hunting
(48946, 0, 0, 0, 0, 'What say you?', 28153), -- The Order of Embers
(48944, 0, 1, 0, 0, 'The opening must be here somewhere...', 28153), -- Unlocking History
(48963, 0, 0, 0, 0, 'I\'ll meet you inside, $c.', 28153), -- Diversionary Tactics
(51134, 6, 0, 0, 0, 'What\'s this?', 0), -- If Bones Could Talk
(48943, 0, 6, 0, 0, 'Have you found anything salvageable?', 28153), -- Salvage Rights
(48942, 0, 1, 0, 0, 'We should drive the yetis back from the road. Having a major trade route cut off by monsters isn\'t going to help our fight against the coven.', 28153), -- Yeti to Rumble
(52075, 0, 0, 0, 0, 'Were you able to kill any of those monsters?', 28153), -- Boned
(48179, 0, 1, 0, 0, 'Were you able to help the others?', 28153), -- Rescue Rangers
(48183, 0, 0, 0, 0, 'We would appreciate any runic power cores from the Awoken Guardians you might find.', 28153), -- The Hills Are Alive
(48182, 0, 1, 0, 0, 'Power within those cairns does not bode well for anyone in Drustvar.', 28153), -- Total Cairnage
(48475, 1, 0, 0, 0, 'Stranger, lend me your aid! I am ensnared in a witch\'s foul magic and I do not know how much longer I can resist! Destroy the circle binding me!', 0), -- Seeing Spirits
(48524, 0, 6, 0, 0, 'Did you go into the mines? What was it like in there?', 28153), -- Culling the Coven
(48523, 0, 6, 0, 0, 'Is she gone?', 28153), -- The Murderous Matron
(48520, 0, 6, 0, 0, 'Have you confronted the strange women?', 28153), -- The Three Sisters
(48519, 0, 1, 0, 0, 'We can begin evacuating on your mark.', 28153), -- Hope They Can't Swim
(49295, 0, 6, 0, 0, 'How\'s our flank looking?', 28153), -- Clear-Cutting
(48518, 0, 6, 0, 0, 'Were there any survivors?', 28153), -- Save Who We Can
(48883, 0, 0, 0, 0, 'Must... catch...', 28153), -- Big Gulls Won't Die
(48882, 0, 0, 0, 0, 'What\'s... this?', 0), -- I Like Fish Guts and I Cannot Lie
(48904, 0, 0, 0, 0, 'Almost gone...', 28153), -- Take the Bait
(48880, 0, 0, 0, 0, 'Are they... gone?', 28153), -- Mean Gulls
(49242, 0, 1, 0, 0, 'These quillrats are truly a menace!', 28153), -- Quill or Be Quilled
(48165, 6, 6, 0, 0, 'Is the deed done?', 28153), -- Harmful If Swallowed
(48170, 0, 547, 0, 0, 'Were you able to catch enough bloodflies?', 28153), -- Once Bitten, Twice Shy
(48113, 6, 6, 0, 0, 'Have you had any luck at the onion field?', 28153), -- A Pungent Solution
(48111, 0, 6, 0, 0, 'What have you learned from the villagers?', 28153), -- Trial by Superstition
(48110, 0, 1, 0, 0, 'We must be prepared. Anywhere can harbor an ambush here.', 28153), -- In Case of Ambush
(48109, 0, 6, 0, 0, 'Has our foe been sufficiently blinded?', 28153), -- The Woods Have Eyes
(48283, 0, 6, 0, 0, 'What is your business here, mainlander?', 28153), -- Standing Accused
(47289, 0, 0, 0, 0, 'This is going to be the best tea party ever!', 0), -- Teddies and Tea
(47950, 0, 1, 0, 0, 'Into the flames with that foul thing!', 28153), -- Cured Ham
(47948, 0, 1, 0, 0, 'Roland? Oh, that poor soul.', 28153), -- Pork Chop
(47947, 0, 1, 0, 0, 'Did you get rid of those beasts?', 28153), -- Big Bad Wolves
(47946, 0, 1, 0, 0, 'Up here they\'re safe from those monsters. Hopefully we can sort this mess out and return them to normal.', 28153), -- Save Their Bacon
(48683, 0, 603, 0, 0, 'The Wicker Man must be destroyed!', 28153), -- Changing Seasons
(48678, 0, 1, 0, 0, 'You must bring the correct offerings if you wish to show us your understanding.', 28153), -- Questionable Offerings
(48805, 1, 0, 0, 0, 'Woah! You found our relics! Aren\'t they neat?', 0), -- Research Recovery
(48804, 0, 1, 0, 0, 'Hey! Are you gonna help my friends?', 28153), -- Mistakes Were Made
(48793, 1, 0, 0, 0, 'Hey! You found our stuff!', 0), -- The Adventurer's Society
(47968, 0, 6, 0, 0, '<The town\'s ledger lists a record of the comings and goings of people and goods through the city of Fallhaven.>', 28153), -- Signs and Portents
(51889, 0, 0, 0, 0, 'These shadows are loud. Can you fix that, too?', 28153), -- The Wrath of Grapes
(52837, 1, 0, 0, 0, 'Do you ever wish to retry your fate?  Perhaps, for a special armor piece, a weapon or a trinket of great power?\n\nFor a price, I will provide you a seal that twists fate and grants an extra result at a past chance. \n\nOnce you possess a seal, it will activate after defeating powerful foes in difficult dungeons and raids.\n\nChoose how you want to pay wisely, for two seals a week is all the power you can manage.', 0), -- Seal of Wartorn Fate: War Resources
(52835, 0, 1, 0, 0, 'Do you ever wish to retry your fate?  Perhaps, for a special armor piece, a weapon or a trinket of great power?\n\nFor a price, I will provide you a seal that twists fate and grants an extra result at a past chance. \n\nOnce you possess a seal, it will activate after defeating powerful foes in difficult dungeons and raids.\n\nChoose how you want to pay wisely, for two seals a week is all the power you can manage.', 0), -- Seal of Wartorn Fate: Marks of Honor
(52834, 1, 0, 0, 0, 'Do you ever wish to retry your fate?  Perhaps, for a special armor piece, a weapon or a trinket of great power?\n\nFor a price, I will provide you a seal that twists fate and grants an extra result at a past chance. \n\nOnce you possess a seal, it will activate after defeating powerful foes in difficult dungeons and raids.\n\nChoose how you want to pay wisely, for two seals a week is all the power you can manage.', 0), -- Seal of Wartorn Fate: Gold
(48768, 0, 0, 0, 0, 'Damn those pirates!$b$bHave you recovered the bars?', 28153), -- Brined Justice
(48761, 0, 0, 0, 0, 'I can\'t stand spiders.$b$b<Myra shudders.>$b$bHave you dealt with them yet?', 28153), -- Spiderphobia
(48764, 0, 0, 0, 0, 'Did you get my mining pick back?', 0), -- Don't Pick a Fight
(53035, 0, 0, 0, 0, 'I foresee that you will follow the shrouded star, and walk the paths it reveals.', 28153), -- A Shrouded Path Through Time
(49223, 0, 0, 0, 0, 'Don\'t let him get away this time!', 28153), -- The Long Con
(53097, 0, 1, 0, 0, 'Find the circle, pierce the veil. Only in oblivion can you find it.', 28153), -- Despondent Ablutions
(50386, 0, 1, 0, 0, 'Ignorance of our enemy will invariably lead to defeat.', 28153), -- Flush Them Out
(50368, 0, 0, 0, 0, 'We have to kill that thing!', 28153), -- Terror of the Kraul
(50340, 0, 0, 0, 0, 'Keep an eye out for anything useful. This place is very dangerous.', 0), -- Steal Them Back
(50367, 0, 0, 0, 0, 'Do you have something for me?', 28153), -- Anger in a Bottle
(50365, 0, 0, 0, 0, 'I hope I\'m wrong, but I\'ve got a bad feeling about this.', 28153), -- Run For the Hills
(50363, 0, 0, 0, 0, 'We can use them for labor, food, and even pets!', 28153), -- War Pigs
(50353, 0, 1, 0, 0, 'Please, find the prisoners!', 28153), -- Boaring Company
(50088, 669, 669, 0, 0, 'That\'s that, then.', 28153), -- Golden Fields Forever
(50069, 0, 669, 0, 0, 'This is MY home!', 28153), -- Goldfield's War
(50065, 669, 0, 0, 0, 'For the last time, I\'m not leaving! I was here first, THEY can leave!', 0), -- A Reason to Stay
(50041, 669, 0, 0, 0, 'Pretty sure I\'ll have to start shootin\' my dinnerware, and I only have three sets. Hurry up, will you?', 0), -- A Pocketful of Shells
(51314, 1, 0, 0, 0, 'We need that grain!', 0), -- Grain Drain
(49960, 0, 669, 0, 0, 'If I could rate Humphrey, I\'d give him at least a twelve out of ten.', 28153), -- Sic 'Em!
(49886, 0, 1, 0, 0, 'Humphrey\'s a good boy, isn\'t he? Of course he is.', 28153), -- Follow Your Nose
(50135, 0, 1, 0, 0, 'Have you found those mystics yet? These vines are growing like crazy!', 28153), -- Stop Vining!
(50134, 1, 1, 0, 0, 'Do you have the parts yet?', 28153), -- Gadgets and Gizmos Aplenty
(51209, 0, 0, 0, 0, 'Did it work!?', 28153), -- Mighty Grokkfist
(51208, 0, 0, 0, 0, 'Were you able to recover some of the grain?', 28153), -- Wheat A Minute
(51504, 1, 0, 0, 0, 'Are those cookies I smell!?', 0), -- Cookie Delivery
(51207, 0, 1, 0, 0, 'How\'d my giant treats work out?', 28153), -- Ettin It Done
(51204, 0, 1, 0, 0, 'Did you take care of their pack leader?', 28153), -- WANTED: Razorclaw Alpha
(51200, 0, 1, 0, 0, 'Have you found her?', 28153), -- The Black Sheep
(51203, 0, 1, 0, 0, 'I wish there was a better way.', 28153), -- Cry Wolf
(51215, 1, 1, 0, 0, 'Were you able to collect enough milk?', 28153), -- Milking Goats
(51492, 1, 0, 0, 0, 'Were you able to find any powder, dear?', 0), -- Gunpowder Plot
(51251, 1, 0, 0, 0, 'If only Lizzie were still here...', 0), -- Basement Dwellers
(50773, 0, 0, 0, 0, 'I can\'t wait to see how this goes.', 28153), -- You're a Shark
(50698, 0, 1, 0, 0, 'Never underestimate Kul Tiran weaponry!', 28153), -- Problem Solving with Gunpowder
(50679, 1, 1, 0, 0, 'We cannot allow this fort to fall!', 28153), -- Piercing the Shield
(50672, 1, 1, 0, 0, 'We can use the naga\'s weapons against them!', 28153), -- Any Ammo Will Do
(50653, 0, 0, 0, 0, 'Did you find any of our soldiers?', 28153), -- Reclaiming our Defenses
(50644, 0, 0, 0, 0, 'How\'s the snake hunting going?', 28153), -- Facing the Invaders
(50649, 0, 0, 0, 0, 'Make sure you don\'t drop any of the beacons. I cannot say I know what will happen.', 28153), -- Filching from Thieves
(50645, 0, 0, 0, 0, 'I can\'t wait to see how this goes.', 28153), -- Eeling in a Big One
(50621, 0, 0, 0, 0, 'Have you found any of our civilians?', 28153), -- Caught in the Net
(50616, 0, 0, 0, 0, 'Is the seawitch dead?', 28153), -- A Bit of a Bind
(50614, 0, 0, 0, 0, 'For a people that live in the sea, the naga seem to have little respect for it.', 28153), -- Freedom for the Sea
(51386, 0, 1, 0, 0, 'The Venture Companies defeat is at hand.  Let\'s get to it!', 28153), -- Battle Victorious
(51220, 0, 0, 0, 0, 'Hurry to it, Ai\'twen\'s saftey is important.', 28153), -- Deep Sea Venture
(51545, 0, 0, 0, 0, 'Time to destroy the Reef Breaker.', 28153), -- Breaker Bad
(51427, 0, 0, 0, 0, 'We are patient.  When you are ready.', 28153), -- I Like Turtles
(51540, 0, 0, 0, 0, 'You\'ll need more of these bombs if we want to destroy the Reef Breaker.', 0), -- Explosive Situation
(51221, 0, 0, 0, 0, 'You must act fast, our time is short.', 28153), -- Response Required
(51371, 0, 0, 0, 0, 'Search for the Seaweed outside and on Makrura Brineshells', 28153), -- Flavorable Offering
(53476, 0, 0, 0, 0, '', 0), -- The Great Sea Scrolls
(51343, 0, 0, 0, 0, 'You must collect the Scroll of Harmonious Fins, Endless Tides and Graceful Breaths.', 0); -- Swimming Lessons

DELETE FROM `quest_request_items` WHERE `ID` IN (13613 /*Rescue the Fallen*/, 13612 /*Mor'shan Defense*/, 29112 /*Demon Seed*/, 29015 /*Miner's Fortune*/, 14006 /*Read the Manual*/, 14004 /*Return to Samophlanger*/, 29090 /*A Burning Threat*/, 29027 /*Nugget Slugs*/, 29026 /*Wenikee Boltbucket*/, 14003 /*Samophlange Repair*/, 29089 /*Sludge Beast!*/, 29024 /*Samophlange*/, 29023 /*Samophlange*/, 29022 /*Samophlange*/, 29086 /*Competition Schmompetition*/, 29088 /*Hyena Extermination*/, 29087 /*Sludge Investigation*/, 26769 /*Raging River Ride*/, 14050 /*Gazlowe's Fortune*/, 14049 /*A Most Unusual Map*/, 14042 /*Ammo Kerblammo*/, 14063 /*Mutiny, Mon!*/, 14057 /*Guns. We Need Guns.*/, 14056 /*Glomp is Sitting On It*/, 14046 /*The Baron's Demands*/, 14038 /*Love it or Limpet*/, 14067 /*The Stolen Silver*/, 14034 /*Club Foote*/, 13999 /*Who's Shroomin' Who?*/, 14066 /*Investigate the Wreckage*/, 14068 /*Waptor Twapping*/, 13988 /*A Growing Problem*/, 13995 /*King of Centaur Mountain*/, 14072 /*Flushing Out Verog*/, 13998 /*In Fungus We Trust*/, 13992 /*A Little Diversion*/, 13968 /*The Tortusk Takedown*/, 13963 /*By Hook Or By Crook*/, 31813 /*Dagra the Fierce*/, 27998 /*Sweet, Merciless Revenge*/, 27996 /*Orders Are For the Living*/, 27988 /*Plague...Plague Everywhere!*/, 27974 /*This Land is Our Land*/, 13973 /*The Grol'dom Militia*/, 13878 /*Through Fire and Flames*/, 25251 /*Final Confrontation*/, 25214 /*Escape Velocity*/, 25203 /*What Kind of Name is Chip, Anyway?*/, 25200 /*Shredder Shutdown*/, 25123 /*Throw It On the Ground!*/, 25122 /*Morale Boost*/, 25058 /*Mine Disposal, the Goblin Way*/, 24942 /*Zombies vs. Super Booster Rocket Boots*/, 24945 /*Three Little Pygmies*/, 24929 /*Send a Message*/, 24925 /*Free the Captives*/, 24901 /*Town-In-A-Box: Under Attack*/, 24868 /*Surrender or Else!*/, 24864 /*Irresistible Pool Pony*/, 24858 /*Bilgewater Cartel Represent*/, 24817 /*A Goblin in Shark's Clothing*/, 24671 /*Cluster Cluck*/, 14242 /*Precious Cargo*/, 14238 /*Infrared = Infradead*/, 14236 /*Weed Whacker*/, 14021 /*Miner Troubles*/, 14473 /*It's Our Problem Now*/, 14019 /*Monkey Business*/, 14474 /*Goblin Escape Pods*/, 14115 /*Pirate Party Crashers*/, 14070 /*Do it Yourself*/, 14071 /*Rolling with my Homies*/, 14069 /*Good Help is Hard to Find*/, 14075 /*Trouble in the Mines*/, 25177 /*Storming the Beaches*/, 25173 /*From Bad to Worse*/, 25169 /*The War of Northwatch Aggression*/, 25168 /*Purge the Valley*/, 25165 /*Never Trust a Big Barb and a Smile*/, 25167 /*Breaking the Chain*/, 31812 /*Zunta, The Pet Tamer*/, 25259 /*Gaur Icehorn*/, 25258 /*Griswold Hanniston*/, 25257 /*Ghislania*/, 25195 /*That's the End of That Raptor*/, 25194 /*Unbidden Visitors*/, 25192 /*Raggaran's Fury*/, 25188 /*Watershed Patrol*/, 25187 /*Lost in the Floods*/, 25206 /*Ignoring the Warnings*/, 25205 /*The Wolf and The Kodo*/, 25236 /*Thunder Down Under*/, 32471 /*Apple Crushing [PH]*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(13613, 0, 0, 0, 0, 'Have you administered the salve to our fallen warriors, $r?', 30706), -- Rescue the Fallen
(13612, 0, 0, 0, 0, 'Was your hunt successful, $r?', 30706), -- Mor'shan Defense
(29112, 0, 0, 0, 0, 'What did you find at the top of the mountain?', 0), -- Demon Seed
(29015, 0, 0, 0, 0, 'If only we knew which one of the miners had found the emerald, it\'d be a walk in the park...', 30706), -- Miner's Fortune
(14006, 0, 0, 0, 0, 'Did you find Copperplug?', 30706), -- Read the Manual
(14004, 0, 0, 0, 0, 'Is that my samophlange? I don\'t even recognize it.', 0), -- Return to Samophlanger
(29090, 0, 0, 0, 0, 'I may be old and retired, but my mind is still as sharp as my sword.', 30706), -- A Burning Threat
(29027, 0, 0, 0, 0, 'Do you have the nugget slugs, $n?  I\'ve been eyeing this Samophlange and I can\'t wait to tinker with it.', 30706), -- Nugget Slugs
(29026, 0, 0, 0, 0, 'I\'m very busy with my work, $c.  Unless you have something for me, it\'d be best if you moved along...', 0), -- Wenikee Boltbucket
(14003, 4, 0, 0, 0, 'Did you say ... samophlange!?', 0), -- Samophlange Repair
(29089, 0, 0, 0, 0, 'So? Did you see what\'s going on at the Sludge Fen?', 30706), -- Sludge Beast!
(29024, 6, 0, 0, 0, 'Oh, you\'re back, $n! Do you have the samophlange?', 0), -- Samophlange
(29023, 0, 0, 0, 0, 'The console lights are dimmed and the gauges and dials all read at their zero positions, everything idling.', 30706), -- Samophlange
(29022, 0, 0, 0, 0, 'Blinking lights on the control console indicate that the main control valves have not been closed off.', 30706), -- Samophlange
(29086, 0, 0, 0, 0, 'I can\'t believe they would stoop so low! Did you get my blueprints back?', 30706), -- Competition Schmompetition
(29088, 0, 0, 0, 0, 'I should have brought earplugs. I didn\'t realize the Barrens could be so noisy.', 30706), -- Hyena Extermination
(29087, 0, 0, 0, 0, 'My favorite wrench is missing and all my tools are muddy.', 30706), -- Sludge Investigation
(26769, 6, 0, 0, 0, 'Welcome, $c. Fresh off the boat from Ratchet? Any news?', 0), -- Raging River Ride
(14050, 25, 25, 0, 0, 'I\'m going to close my eyes, $n. And when I open them, I expect to see wall-to-wall treasure. Deal?', 30706), -- Gazlowe's Fortune
(14049, 0, 0, 0, 0, 'Was Baron Longshore alive? Do you have anything for me?', 0), -- A Most Unusual Map
(14042, 0, 0, 0, 0, 'So... how fares Vice Admiral Hartley? Miserable, I hope?', 30706), -- Ammo Kerblammo
(14063, 1, 0, 0, 0, 'Is that the Maiden\'s Dagger I see weighing anchor in the distance? Did you have anything to do with that?', 0), -- Mutiny, Mon!
(14057, 6, 6, 0, 0, 'Guns, mon. You got the stuff?', 30706), -- Guns. We Need Guns.
(14056, 6, 6, 0, 0, 'You got the cash? That money will go a long way to winnin\' over the hearts and minds of heartless, thoughtless cutthroats.', 30706), -- Glomp is Sitting On It
(14046, 0, 0, 0, 0, 'Get on with it, mate. The guards may be back any moment. Ye know what ta do.', 30706), -- The Baron's Demands
(14038, 0, 0, 0, 0, 'Did we make some nice kersplosions? Did we? ', 30706), -- Love it or Limpet
(14067, 0, 0, 0, 0, 'You look roughed up, $c. Did you tussle with the thieves?', 0), -- The Stolen Silver
(14034, 0, 0, 0, 0, 'You got the goods?', 30706), -- Club Foote
(13999, 274, 0, 0, 0, 'Who are you? Did Helbrim send you? Keep a low profile.', 0), -- Who's Shroomin' Who?
(14066, 0, 0, 0, 0, 'This Horde caravan was not merely robbed. It was savagely brutalized. Crates of supplies have been ripped apart by sharp claws. The wagon has been demolished. The food has been eaten and the silver is gone, and yet useful supplies have been left behind...', 30706), -- Investigate the Wreckage
(14068, 0, 0, 0, 0, 'Where\'s the wittle waptors?', 30706), -- Waptor Twapping
(13988, 1, 1, 0, 0, 'Tonga knows these lands better than any of us, and I believe it physically hurt him to see it torn asunder.', 30706), -- A Growing Problem
(13995, 0, 0, 0, 0, 'Well, I suppose that\'s one way to track down Kurak. What happened up there?', 30706), -- King of Centaur Mountain
(14072, 0, 0, 0, 0, 'Search those tents, $n. Try to ignore the stench.', 30706), -- Flushing Out Verog
(13998, 0, 0, 0, 0, 'Out with it, $c! What happened at the oasis?', 30706), -- In Fungus We Trust
(13992, 0, 0, 0, 0, 'I love watchin\' these guys scurry all over.', 30706), -- A Little Diversion
(13968, 0, 0, 0, 0, 'Does Tortusk still draw breath?', 30706), -- The Tortusk Takedown
(13963, 0, 6, 0, 0, 'Well, did he squeal?', 30706), -- By Hook Or By Crook
(31813, 0, 0, 0, 0, 'I fear nothing. I will not be defeated!', 30706), -- Dagra the Fierce
(27998, 0, 0, 0, 0, 'Let\'s get going.', 30706), -- Sweet, Merciless Revenge
(27996, 0, 0, 0, 0, 'You have your orders, $n.', 30706), -- Orders Are For the Living
(27988, 0, 0, 0, 0, 'A couple bodiless spirits aren\'t going to best you, are they?', 30706), -- Plague...Plague Everywhere!
(27974, 0, 0, 0, 0, 'Don\'t test my patience and good will.', 30706), -- This Land is Our Land
(13973, 0, 6, 0, 0, 'I can see smoke from the neighboring building - what\'s going on out there?', 30706), -- The Grol'dom Militia
(13878, 0, 0, 0, 0, 'Hot!', 30706), -- Through Fire and Flames
(25251, 0, 0, 0, 0, '$n, you have to go deal with the Trade Prince before it\'s too late!', 30706), -- Final Confrontation
(25214, 0, 1, 0, 0, 'You still have have more cages to liberate from their Azerothian bonds.', 30706), -- Escape Velocity
(25203, 0, 6, 0, 0, 'Are you going to do something about him? You can\'t just let this stand.', 30706), -- What Kind of Name is Chip, Anyway?
(25200, 0, 1, 0, 0, 'Looks like you might need to tackle one or two more of those Sharks.', 30706), -- Shredder Shutdown
(25123, 0, 5, 0, 0, 'The soulstone is the key, $n!', 30706), -- Throw It On the Ground!
(25122, 0, 5, 0, 0, 'Increase their morale, $n, so that they will run to freedom!', 30706), -- Morale Boost
(25058, 0, 6, 0, 0, 'Boss, do you think you could go back down there and detonate a few more?$B$BThanks!', 30706), -- Mine Disposal, the Goblin Way
(24942, 0, 0, 0, 0, 'You still have a few goblin zombies to deal with, $n. Look sharp, superstar!', 30706), -- Zombies vs. Super Booster Rocket Boots
(24945, 0, 6, 0, 0, 'Um, boss, look, I don\'t know how to say this, but you might have missed one or two of those pygmy witch doctors.$B$BI\'m just saying.', 30706), -- Three Little Pygmies
(24929, 0, 5, 0, 0, '$n, I still hear Yngwie yelling!', 30706), -- Send a Message
(24925, 0, 6, 0, 0, 'Can you free a few more, please?', 30706), -- Free the Captives
(24901, 0, 6, 0, 0, 'That\'s not enough, hon. Can you take care of more of them?', 30706), -- Town-In-A-Box: Under Attack
(24868, 0, 6, 0, 0, 'What\'s wrong?', 30706), -- Surrender or Else!
(24864, 0, 1, 0, 0, 'That\'s not enough hatchlings.', 30706), -- Irresistible Pool Pony
(24858, 0, 5, 0, 0, 'There are still some naga banners down there that need to be \'sploded and replaced!', 30706), -- Bilgewater Cartel Represent
(24817, 0, 5, 0, 0, 'That monstrously humongous shark is not dead yet! Do I have to do everything myself?', 30706), -- A Goblin in Shark's Clothing
(24671, 0, 274, 0, 0, 'Not enough cluckers, $n. We\'ll all starve.', 30706), -- Cluster Cluck
(14242, 0, 6, 0, 0, 'Perhaps you can help me to get out of this arcane cage?', 30706), -- Precious Cargo
(14238, 0, 6, 0, 0, 'You got them all?', 30706), -- Infrared = Infradead
(14236, 0, 5, 0, 0, 'There are still too many for us to get through.$B$BHave faith in yourself, $n. Let your true warrior heart shine through.', 30706), -- Weed Whacker
(14021, 0, 6, 0, 0, 'How did it go? How much kaja\'mite were you able to get?', 30706), -- Miner Troubles
(14473, 0, 6, 0, 0, 'What are you gonna do when Maxx Avalanche comes down on you, $n?! How\'s the hatchling hunting coming?', 30706), -- It's Our Problem Now
(14019, 0, 6, 0, 0, 'Did it work?', 30706), -- Monkey Business
(14474, 0, 5, 0, 0, 'I still see some out there! Please, $n, go get them before they drown!', 30706), -- Goblin Escape Pods
(14115, 0, 6, 0, 0, 'Was that all of them? I know that I saw a lot rushing in!', 30706), -- Pirate Party Crashers
(14070, 0, 6, 0, 0, 'Is that all of them? Let\'s cross-check the list real quick just to be sure.', 30706), -- Do it Yourself
(14071, 0, 6, 0, 0, 'The party\'s almost ready. How was your trip to town?', 30706), -- Rolling with my Homies
(14069, 0, 6, 0, 0, 'A good start, $g sir : ma\'am;, but might I suggest that you may want to make an example of a few more?', 30706), -- Good Help is Hard to Find
(14075, 0, 6, 0, 0, 'I don\'t know, boss. I\'m still getting reports of worms eating all of the kaja\'mite in the mines.$B$BYou should head back down there and take care of them.', 30706), -- Trouble in the Mines
(25177, 0, 25, 0, 0, 'Return to the beach and finish the job!', 30706), -- Storming the Beaches
(25173, 0, 25, 0, 0, 'You have your orders, $n. The safety of Durotar is in question. Complete the task before you or hang your head in shame.$b$bShow your honor and defeat the humans of Tiragarde Keep.', 30706), -- From Bad to Worse
(25169, 0, 0, 0, 0, 'Destroy those humans, $n.', 30706), -- The War of Northwatch Aggression
(25168, 0, 0, 0, 0, 'Slay them all.', 30706), -- Purge the Valley
(25165, 0, 0, 0, 0, 'You got the jujus, ya?', 30706), -- Never Trust a Big Barb and a Smile
(25167, 0, 0, 0, 0, 'We gotta get rid of these humans, $c.', 30706), -- Breaking the Chain
(31812, 0, 0, 0, 0, 'Who be sendin\' you to face Zunta?', 30706), -- Zunta, The Pet Tamer
(25259, 0, 0, 0, 0, 'You don\'t stand a chance against Gaur.', 30706), -- Gaur Icehorn
(25258, 0, 0, 0, 0, 'How did you do?', 30706), -- Griswold Hanniston
(25257, 0, 0, 0, 0, 'How\'d you fare?', 30706), -- Ghislania
(25195, 0, 0, 0, 0, 'The raptor has always been a quick adapter.', 30706), -- That's the End of That Raptor
(25194, 0, 0, 0, 0, 'Just beat on \'em, mon.  Trust Zen\'Taji, they will run.  It is no big thing.', 30706), -- Unbidden Visitors
(25192, 0, 0, 0, 0, 'Quilboar!  Kill them!', 30706), -- Raggaran's Fury
(25188, 0, 0, 0, 0, 'How goes your journey, $c?', 30706), -- Watershed Patrol
(25187, 0, 0, 0, 0, 'What have you seen?', 30706), -- Lost in the Floods
(25206, 0, 0, 0, 0, 'Elementals?  Pfuh!  No match for the power of the Horde.', 30706), -- Ignoring the Warnings
(25205, 0, 0, 0, 0, 'Pay close attention to the meaning behind my words, child.', 30706), -- The Wolf and The Kodo
(25236, 0, 0, 0, 0, 'I need that canyon clean, $n.  Water is normally scarce in Durotar... we should take advantage of this.', 30706), -- Thunder Down Under
(32471, 0, 0, 0, 0, 'You got those parts for me, or what? I\'m busy here!', 0); -- Apple Crushing [PH]

UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=30706 WHERE `ID`=876; -- Serena Bloodfeather
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you killed 6 Witchwing Slayers yet? Justice must be dealt to them for their vicious attacks on the Horde.', `VerifiedBuild`=30706 WHERE `ID`=875; -- Harpy Lieutenants
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='The Witchwing harpies live in the Dry Hills to the north.', `VerifiedBuild`=30706 WHERE `ID`=867; -- Harpy Raiders
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=30706 WHERE `ID`=858; -- Ignition
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Did you swash some buckles, $n? Did you Buccan their neers?', `VerifiedBuild`=30706 WHERE `ID`=887; -- Southsea Freebooters
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=30706 WHERE `ID`=895; -- WANTED: Cap'n Garvey
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Did you get King Reaperclaw\'s horn, $n? I need to test my first smart drink!', `VerifiedBuild`=30706 WHERE `ID`=865; -- It's Gotta be the Horn
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `CompletionText`='Fill my hand with medals from their dead and I will know that vengeance has been given to my fallen privateers.', `VerifiedBuild`=30706 WHERE `ID`=891; -- A Captain's Vengeance
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=30706 WHERE `ID`=4021; -- Counterattack!
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='How goes your hunting, $n?', `VerifiedBuild`=30706 WHERE `ID`=855; -- Centaur Bracers
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Is Hezrul defeated, $n?', `VerifiedBuild`=30706 WHERE `ID`=852; -- Hezrul Bloodmark
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='What else have you brought me?' WHERE `ID`=880; -- Altered Beings
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Did you find Verog, $n?', `VerifiedBuild`=30706 WHERE `ID`=851; -- Verog the Dervish
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you been to the nests, $n?', `VerifiedBuild`=30706 WHERE `ID`=905; -- Into the Raptor's Den
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='The great cat calls to you, $n.', `VerifiedBuild`=30706 WHERE `ID`=881; -- Echeyakee
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Hello, $n. Do you have Kodobane\'s head for me?', `VerifiedBuild`=30706 WHERE `ID`=850; -- Kolkar Leaders
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='How goes your hunt, $n?', `VerifiedBuild`=30706 WHERE `ID`=903; -- Hunting the Huntress
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=30706 WHERE `ID`=845; -- The Zhevra
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you been to the Forgotten Pools, $n? Did you find anything?', `VerifiedBuild`=30706 WHERE `ID`=870; -- The Forgotten Pools
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Do you have the spores, $n? My associates and I are eager to study this phenomenon...', `VerifiedBuild`=30706 WHERE `ID`=848; -- Fungal Spores
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=13975; -- Crossroads Caravan Delivery
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='The quilboar will pay for this, $n. I swear it.', `VerifiedBuild`=30706 WHERE `ID`=899; -- Consumed by Hatred
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=30706 WHERE `ID`=13961; -- Drag it Out of Them
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='How goes your search for the supplies, $n? I trust the quilboar fall under your strength easily.', `VerifiedBuild`=30706 WHERE `ID`=5041; -- Supplies for the Crossroads
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Cut off the head of their leader, and chaos ensues, $n. Learn this lesson well. It will aid you in the future.', `VerifiedBuild`=30706 WHERE `ID`=872; -- The Far Watch Offensive
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=30706 WHERE `ID`=844; -- Plainstrider Menace
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `CompletionText`='...Assaulting our stables? The audacity!$B$BThe destruction in southern barrens has pushed the Razormane up here, and they\'re been stealing our supplies with renewed ferocity.$B$BThe longer it takes to stop these attacks, the harder it will be to keep the people of the Crossroads armed and fed.', `VerifiedBuild`=30706 WHERE `ID`=871; -- In Defense of Far Watch
UPDATE `quest_request_items` SET `EmoteOnComplete`=15, `EmoteOnCompleteDelay`=200 WHERE `ID`=840; -- Conscript of the Horde
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='What is this, goblin? You are not from these parts.' WHERE `ID`=25267; -- Message for Saurfang
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='What be your business in Orgrimmar?' WHERE `ID`=25266; -- Warchief's Emissary
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=30706 WHERE `ID`=25243; -- She Loves Me, She Loves Me NOT!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `CompletionText`='Let\'s see what you have there, $n.', `VerifiedBuild`=30706 WHERE `ID`=25201; -- The Ultimate Footbomb Uniform
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=30706 WHERE `ID`=25110; -- Kaja'Cola Gives You IDEAS! (TM)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=30706 WHERE `ID`=25066; -- The Pride of Kezan
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=30706 WHERE `ID`=25093; -- The Heads of the SI:7
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=396, `CompletionText`='There are yet more Alliance paratroopers that need to be dispatched if we\'re to get about the business of escaping from this island, $n.', `VerifiedBuild`=30706 WHERE `ID`=25024; -- Repel the Paratroopers
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `CompletionText`='No time like the present to be done with the simple task I put before you, $n. Wouldn\'t you agree?', `VerifiedBuild`=30706 WHERE `ID`=24954; -- Children of a Turtle God
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=24952; -- Rocket Boot Boost
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=30706 WHERE `ID`=24946; -- Rockin' Powder
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=30706 WHERE `ID`=24859; -- Naga Hide
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='$n, take it easy on Grapplehammer. He\'s a genius, but he\'s got a fragile ego.' WHERE `ID`=24816; -- Who's Top of the Food Chain Now?
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=30706 WHERE `ID`=24744; -- The Biggest Egg Ever
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=30706 WHERE `ID`=24741; -- Trading Up
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=14234; -- The Enemy of My Enemy
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='$n, find anything interesting in the cavern?' WHERE `ID`=14233; -- Orcs Can Write?
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=30706 WHERE `ID`=14014; -- Get Our Stuff Back!
UPDATE `quest_request_items` SET `CompletionText`='Oh, $n, it\'s you. What an unexpected surprise.$B$B<The Trade Prince rubs his hands together.>' WHERE `ID`=14126; -- Life Savings
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=30706 WHERE `ID`=14124; -- Liberate the Kaja'mite
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=30706 WHERE `ID`=14121; -- Robbing Hoods
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=30706 WHERE `ID`=14123; -- Waltz Right In
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Do you have it all, $n? I can\'t wait to see it on you!$B$BYou bought the good stuff, right?' WHERE `ID`=14109; -- The New You
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=397, `CompletionText`='We\'re counting on you, $n!', `VerifiedBuild`=30706 WHERE `ID`=24488; -- The Replacements
UPDATE `quest_request_items` SET `EmoteOnCompleteDelay`=1000 WHERE `ID`=25473; -- Kaja'Cola
UPDATE `quest_request_items` SET `EmoteOnComplete`=25, `EmoteOnIncomplete`=25, `VerifiedBuild`=30706 WHERE `ID`=25178; -- Shipwreck Searching
UPDATE `quest_request_items` SET `EmoteOnComplete`=25, `EmoteOnIncomplete`=25, `VerifiedBuild`=30706 WHERE `ID`=25176; -- Exploiting the Situation
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26807; -- Return to Eitrigg
UPDATE `quest_request_items` SET `CompletionText`='Have you yet entered Skull Rock, $n?  Do you have the Searing Collars?', `VerifiedBuild`=30706 WHERE `ID`=25262; -- Skull Rock
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26806; -- Reports to Orgrimmar
UPDATE `quest_request_items` SET `EmoteOnComplete`=25, `EmoteOnIncomplete`=25, `CompletionText`='The scrolls, $n, the scrolls!', `VerifiedBuild`=30706 WHERE `ID`=25232; -- The Burning Blade
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `CompletionText`='You wouldn\'t think it from a guy like my boss Gazlowe, but he always seemed to know the score. \"Don\'t be afraid to take that big step,\" he said.$b$bHarpies won\'t stop bothering us and the caravans won\'t stop being attacked unless we do something about it, eh?', `VerifiedBuild`=30706 WHERE `ID`=835; -- Securing the Lines

UPDATE `quest_request_items` SET `VerifiedBuild`=30706 WHERE `ID` IN (13970, 14122, 25170, 25260, 25190, 25193, 834, 29401);

DELETE FROM `quest_request_items` WHERE `ID` IN (13798 /*Rain of Destruction*/, 13797 /*Dirty Deeds*/, 26447 /*Diabolical Plans*/, 13801 /*Dead Elves Walking*/, 13730 /*Playing With Felfire*/, 26448 /*Destroy the Legion*/, 13712 /*To the Rescue!*/, 13651 /*Needs a Little Lubrication*/, 13628 /*Got Wood?*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(13798, 0, 0, 0, 0, 'Has the enemy fallen, $n?', 30920), -- Rain of Destruction
(13797, 0, 0, 0, 0, 'Have you collected the ore we need?', 30920), -- Dirty Deeds
(26447, 6, 0, 0, 0, 'What do you have there, $t brother : sister;?', 0), -- Diabolical Plans
(13801, 0, 0, 0, 0, 'Did you rid the barrows of the ghosts?', 30920), -- Dead Elves Walking
(13730, 0, 0, 0, 0, 'Did you fill up that canister for me, $c?', 30920), -- Playing With Felfire
(26448, 0, 5, 0, 0, 'Are there not demons yet standing?  You call yourself a $r?  This is no time to be taking a break from the fighting!', 30920), -- Destroy the Legion
(13712, 0, 0, 0, 0, 'Work complete!', 30920), -- To the Rescue!
(13651, 0, 0, 0, 0, 'Were you able to collect the oil we need, $c?', 30920), -- Needs a Little Lubrication
(13628, 0, 0, 0, 0, 'Quite an entrance, $r. What can I do for you?', 0); -- Got Wood?

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=26449; -- Never Again!
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='You kill dem outrunners, $n.', `VerifiedBuild`=30920 WHERE `ID`=6503; -- Ashenvale Outrunners

UPDATE `quest_request_items` SET `VerifiedBuild`=30920 WHERE `ID`=13640;

DELETE FROM `quest_request_items` WHERE `ID` IN (13842 /*Dread Head Redemption*/, 13962 /*Stalemate*/, 13884 /*Put Out The Fire*/, 13983 /*Building Your Own Coffin*/, 13980 /*They're Out There!*/, 13977 /*Mass Production*/, 13947 /*Blastranaar!*/, 13943 /*Breathing Room*/, 13942 /*Set Us Up the Bomb*/, 13901 /*Deep Despair*/, 31814 /*Analynn*/, 13920 /*Before You Go...*/, 13890 /*Keep the Fires Burning*/, 26890 /*The Essence of Aku'Mai*/, 13883 /*Lousy Pieces of Ship*/, 13967 /*Thinning the... Herd?*/, 13806 /*Demon Duty*/, 26449 /*Never Again!*/, 13875 /*Gurtar's Request*/, 13871 /*Security!*/, 13865 /*Wet Work*/, 13815 /*Making Stumps*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(13842, 0, 0, 0, 0, 'Carry on.', 32028), -- Dread Head Redemption
(13962, 0, 0, 0, 0, 'Well, $r? Is Ordanus defeated?', 32028), -- Stalemate
(13884, 0, 33, 0, 0, 'There are yet more lava ragers to be destroyed, $r.', 32028), -- Put Out The Fire
(13983, 0, 0, 0, 0, 'You got those parts I need, friend?', 32028), -- Building Your Own Coffin
(13980, 0, 0, 0, 0, 'Have you eliminated the assassins, $c?', 32028), -- They're Out There!
(13977, 0, 0, 0, 0, 'Whatcha got there, boss?', 0), -- Mass Production
(13947, 0, 0, 0, 0, 'Astranaar is burning!$b$bFor the Horde!', 32028), -- Blastranaar!
(13943, 0, 0, 0, 0, 'Well, $r, have you taught the elves a little humility?', 32028), -- Breathing Room
(13942, 0, 0, 0, 0, 'Let\'s see what you\'ve brought me, $r.', 32028), -- Set Us Up the Bomb
(13901, 0, 0, 0, 0, 'Hello again, $r.$b$bHave you shown the naga the might of the Horde?', 32028), -- Deep Despair
(31814, 0, 0, 0, 0, 'You\'re a curious sort.', 32028), -- Analynn
(13920, 0, 0, 0, 0, 'Yes, $r?', 32028), -- Before You Go...
(13890, 0, 0, 0, 0, 'Well, $c...$b$bHave you done as I asked?', 32028), -- Keep the Fires Burning
(26890, 6, 6, 0, 0, 'How goes your search for the crystals, $n? Do you think they\'ll make an item we can use to stop the naga?', 32028), -- The Essence of Aku'Mai
(13883, 0, 0, 0, 0, 'Were you able to recover that armor plating, $r?', 32028), -- Lousy Pieces of Ship
(13967, 0, 0, 0, 0, 'Well, $n.$b$bIs it done?', 32028), -- Thinning the... Herd?
(13806, 0, 0, 0, 0, 'Have you managed to close the satyr portals, $r?', 32028), -- Demon Duty
(26449, 5, 0, 0, 0, 'Those dreadlords must die soon, $n!', 0), -- Never Again!
(13875, 0, 0, 0, 0, 'Hello, $n.', 0), -- Gurtar's Request
(13871, 0, 0, 0, 0, 'I want to know one thing, $r.$b$bIs that assassin dead?', 32028), -- Security!
(13865, 0, 6, 0, 0, 'Is it done, $c?', 32028), -- Wet Work
(13815, 0, 6, 0, 0, 'Were you able to chop down the enemy\'s trees, $c?', 32028); -- Making Stumps

UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Yes, $c?' WHERE `ID`=24; -- Shadumbra's Head
UPDATE `quest_request_items` SET `EmoteOnComplete`=34, `EmoteOnIncomplete`=34, `VerifiedBuild`=32028 WHERE `ID`=13880; -- Hot Lava
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='What is it, $r?' WHERE `ID`=23; -- Ursangous' Paw
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=32028 WHERE `ID`=216; -- Between a Rock and a Thistlefur
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=14, `CompletionText`='Did you find the charms, $n?  Every moment the furbolgs possess those sacred items, my blood boils with rage!', `VerifiedBuild`=32028 WHERE `ID`=6462; -- Troll Charm
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1918; -- The Befouled Element
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='Did you defeat Chief Murgut, $n?  Did you retrieve his foulweald totem?', `VerifiedBuild`=32028 WHERE `ID`=6621; -- King of the Foulweald
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `CompletionText`='Have you defeated Tideress, $r?', `VerifiedBuild`=32028 WHERE `ID`=25; -- Simmer Down Now
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='What have you there, $c? Could it be....?' WHERE `ID`=2; -- Sharptalon's Claw
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='I hope you can be quick about getting those horns, $n. I\'m heading back to Ratchet soon!', `VerifiedBuild`=32028 WHERE `ID`=6441; -- Satyr Horns

UPDATE `quest_request_items` SET `VerifiedBuild`=32028 WHERE `ID`=6442;

DELETE FROM `quest_request_items` WHERE `ID` IN (26115 /*To Be Horde...*/, 26099 /*Is This Justice?*/, 26098 /*Betrayal at the Grove*/, 26082 /*To Battlescar!*/, 26076 /*Spy Infestation*/, 26075 /*The Turd Problem*/, 14223 /*Peace of Mind*/, 14196 /*Firestarter*/, 14219 /*To the Hilt!*/, 14213 /*Ten Pounds of Flesh*/, 14191 /*Furien's Footsteps*/, 14284 /*A Revenant's Vengeance*/, 14264 /*Wetter Than Wet*/, 14256 /*The Emerging Threat*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(26115, 0, 6, 0, 0, 'Now do you understand?', 32144), -- To Be Horde...
(26099, 0, 1, 0, 0, 'This is justice.', 32144), -- Is This Justice?
(26098, 6, 0, 0, 0, 'He... My child is dead?', 0), -- Betrayal at the Grove
(26082, 0, 5, 0, 0, 'Slay them all!', 32144), -- To Battlescar!
(26076, 0, 6, 0, 0, 'Have you dealt with the spy infestation?', 32144), -- Spy Infestation
(26075, 0, 20, 0, 0, 'Please help. The guards are getting a little uppity.', 32144), -- The Turd Problem
(14223, 0, 0, 0, 0, 'So, is it done, $c?', 32144), -- Peace of Mind
(14196, 0, 0, 0, 0, '', 32144), -- Firestarter
(14219, 0, 0, 0, 0, 'The statue stands expectantly.', 32144), -- To the Hilt!
(14213, 0, 0, 0, 0, 'The brazier silently awaits an offering.', 32144), -- Ten Pounds of Flesh
(14191, 0, 0, 0, 0, '', 32144), -- Furien's Footsteps
(14284, 0, 0, 0, 0, 'Were you able to assist the water revenant?', 32144), -- A Revenant's Vengeance
(14264, 0, 0, 0, 0, 'Tell me, minnow. Have you done as I asked?', 32144), -- Wetter Than Wet
(14256, 0, 0, 0, 0, 'Now you see, $r. This is not a matter to be taken lightly.', 32144); -- The Emerging Threat

UPDATE `quest_request_items` SET `CompletionText`='Could it be....?' WHERE `ID`=14268; -- Deep Impact

UPDATE `quest_request_items` SET `VerifiedBuild`=32144 WHERE `ID` IN (14253, 14257);

DELETE FROM `quest_request_items` WHERE `ID` IN (24529 /*Bad to Worse*/, 24525 /*Keeping the Dogs at Bay*/, 24539 /*When Plants Attack*/, 24519 /*Stalling the Survey*/, 24517 /*Put the Fear in Them*/, 25284 /*Feeding the Fear*/, 24512 /*Warriors' Redemption*/, 25362 /*A Grim Discovery*/, 25346 /*Mountain Giant Muisek*/, 25361 /*A New Cloak's Sheen*/, 25345 /*Faerie Dragon Muisek*/, 25375 /*Taming The Tamers*/, 25374 /*Sasquatch Sighting*/, 25364 /*Alpha Strike*/, 25645 /*Return to Sage Palerunner*/, 25368 /*Verinias the Twisted*/, 25363 /*War on the Woodpaw*/, 25349 /*Twisted Sisters*/, 25373 /*The Hilltop Threat*/, 25338 /*Treant Muisek*/, 25641 /*The Flow of Muisek*/, 25329 /*Might of the Stonemaul*/, 25454 /*Perfect Yeti Hide*/, 25344 /*Ogre Abduction*/, 25342 /*Talk to Swar'jan*/, 25453 /*Improved Quality*/, 25337 /*Hippogryph Muisek*/, 25252 /*Rulers of Dire Maul*/, 25452 /*The Mark of Quality*/, 25336 /*Testing the Vessel*/, 25341 /*The Gordunni Orb*/, 25209 /*The Gordunni Threat*/, 25250 /*Sealing the Dream*/, 25241 /*The Land, Corrupted*/, 25237 /*Tears of Stone*/, 25230 /*More Than Illness*/, 25210 /*Signs of Change*/, 25340 /*Dark Heart*/, 25339 /*Vengeance on the Northspring*/, 14335 /*Chipping In*/, 14334 /*Blubbergut*/, 14393 /*Into the Fray!*/, 14329 /*Not So Fast!*/, 14346 /*Cleansing Our Crevasse*/, 14342 /*Infernal Encroachment*/, 14314 /*Breakout!*/, 14309 /*Calming the Kodo*/, 14311 /*Taking Part*/, 14307 /*Stubborn Winds*/, 14306 /*Pulling Weeds*/, 14246 /*Early Adoption*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(24529, 0, 0, 0, 0, 'How do things look in the quilboar camps, $c?', 32185), -- Bad to Worse
(24525, 0, 1, 0, 0, 'Thank you for helping me with this grim business, $n.', 32185), -- Keeping the Dogs at Bay
(24539, 0, 1, 0, 0, 'Be careful out there. The plants and animals of this jungle are outside of the natural order.', 32185), -- When Plants Attack
(24519, 0, 6, 0, 0, 'Have you taken care of things?', 32185), -- Stalling the Survey
(24517, 0, 1, 0, 0, 'I take great pleasure in striking the Alliance and disappearing into these hills. They must think they are facing far greater numbers.', 32185), -- Put the Fear in Them
(25284, 0, 6, 0, 0, 'Tell me about the guards. Chaos? Fear? Panic? Hm?', 32185), -- Feeding the Fear
(24512, 0, 1, 0, 0, 'It is a dangerous climb up and down the cliffs, but our ability to appear and disappear without warning is what will drive terror into the hearts of our foes.', 32185), -- Warriors' Redemption
(25362, 1, 1, 0, 0, 'Take my words seriously, $c, the Grimtotem clan is evil. If you\'ve found their whereabouts, then it\'s up to you to return and strike the first blow against their clan... before they can come into our own lands and raze our own villages, or pilfer our lands.', 32185), -- A Grim Discovery
(25346, 0, 0, 0, 0, 'Were you able to capture the mountain giants?', 32185), -- Mountain Giant Muisek
(25361, 1, 1, 0, 0, 'The sprite darters can be dangerous critters when provoked. Be careful when dealing with them, $c. And be even more careful of any night elves in the area. The pestering fools tend to hold up in the forests also.$B$BWhen you\'ve gotten enough of the wings, let me know, I\'ll be sure to reward you well!', 32185), -- A New Cloak's Sheen
(25345, 0, 0, 0, 0, 'Were you able to capture the muisek of the faerie dragons?', 32185), -- Faerie Dragon Muisek
(25375, 0, 0, 0, 0, 'Make sure the tamers are slain, $n.', 32185), -- Taming The Tamers
(25374, 0, 0, 0, 0, 'Take caution, $n. The beast they hold will be far more ferocious than any yeti you\'ve found in this forest.', 32185), -- Sasquatch Sighting
(25364, 0, 5, 0, 0, 'The alphas can be found at their own camps, with the lesser gnolls surrounding the outskirts.', 32185), -- Alpha Strike
(25645, 0, 0, 0, 0, 'You\'ve returned. What have you found?', 0), -- Return to Sage Palerunner
(25368, 0, 6, 0, 0, 'You must free me from Verinias\'s grasp! I can grant the amulet to you if you do...', 32185), -- Verinias the Twisted
(25363, 5, 5, 0, 0, 'We drive them back, and yet they still attack!  Someone or something must be driving them into a frenzy... oh, you have returned, eh $n?  Do you have the manes I require for the bounty to be met?', 32185), -- War on the Woodpaw
(25349, 0, 0, 0, 0, 'Stalk the woods well, $n.', 32185), -- Twisted Sisters
(25373, 0, 0, 0, 0, 'The gordunni near the camp must be dealt with.', 32185), -- The Hilltop Threat
(25338, 6, 6, 0, 0, 'Were you able to capture the wandering forest walkers?', 32185), -- Treant Muisek
(25641, 0, 0, 0, 0, 'I sense something familiar in your presence...', 0), -- The Flow of Muisek
(25329, 0, 0, 0, 0, 'Is it done?', 32185), -- Might of the Stonemaul
(25454, 6, 0, 0, 0, 'What\'s this, $n - you\'ve got something special for me?', 0), -- Perfect Yeti Hide
(25344, 0, 0, 0, 0, 'Well?', 32185), -- Ogre Abduction
(25342, 0, 0, 0, 0, 'Yes?', 0), -- Talk to Swar'jan
(25453, 5, 5, 0, 0, 'Are the Feral Scar yeti still there? Did you get the leather?', 32185), -- Improved Quality
(25337, 6, 6, 0, 0, 'Were you able to capture the hippogryphs?', 32185), -- Hippogryph Muisek
(25252, 0, 1, 0, 0, 'Make sure you\'re killing the Gordok guards, whelp! There\'s strategy behind this even if your peon brain can\'t understand it.', 32185), -- Rulers of Dire Maul
(25452, 6, 6, 0, 0, 'Were you able to get a stack of ten thick yeti hides?  My leather goods are second to none, and I\'ll share a sampling with you should you have the hides.$B$B', 32185), -- The Mark of Quality
(25336, 0, 0, 0, 0, 'Did you get the beast muisek?', 32185), -- Testing the Vessel
(25341, 1, 1, 0, 0, 'Do you have the orb?', 32185), -- The Gordunni Orb
(25209, 0, 1, 0, 0, 'The ruins are right to the south, $n. Don\'t dawdle.', 32185), -- The Gordunni Threat
(25250, 0, 1, 0, 0, 'The portal must be sealed, $n. Do not falter.', 32185), -- Sealing the Dream
(25241, 0, 1, 0, 0, 'Do not shy from the task, $n. The giants are part of the great cycle as we all are, and they do not deserve this anguish.', 32185), -- The Land, Corrupted
(25237, 0, 0, 0, 0, 'The tears are among the very rocks that the giants themselves rise from. There should be loose ones near the base of these large monoliths.', 32185), -- Tears of Stone
(25230, 0, 0, 0, 0, 'The task may seem cruel, $n, but it must be done. We must preserve balance.', 32185), -- More Than Illness
(25210, 25, 25, 0, 0, 'This is a sad task, $n, but necessary.', 32185), -- Signs of Change
(25340, 0, 0, 0, 0, 'The hate that Edana spreads across the land must be stopped.', 32185), -- Dark Heart
(25339, 0, 0, 0, 0, 'The wings of the Northspring harpies are black as the night; do not take your eyes off of them, lest they disappear into darkness.', 32185), -- Vengeance on the Northspring
(14335, 0, 0, 0, 0, 'Has our lobstrok problem been dealt with, $c?', 32185), -- Chipping In
(14334, 0, 0, 0, 0, 'You get \'im, mon?', 32185), -- Blubbergut
(14393, 0, 0, 0, 0, '', 32185), -- Into the Fray!
(14329, 0, 0, 0, 0, 'Have you discovered my daughter\'s whereabouts, $r?', 32185), -- Not So Fast!
(14346, 0, 0, 0, 0, 'Have you dealt with the naga in our crevasse, $n?', 32185), -- Cleansing Our Crevasse
(14342, 0, 0, 0, 0, 'How are things at Mannoroc Coven, $r?', 32185), -- Infernal Encroachment
(14314, 0, 0, 0, 0, 'Have my people been freed, $r?', 32185), -- Breakout!
(14309, 0, 0, 0, 0, 'Well, did it work?', 32185), -- Calming the Kodo
(14311, 0, 0, 0, 0, 'Have you planted the Cenarion Seeds, $c?', 32185), -- Taking Part
(14307, 0, 0, 0, 0, 'How goes our plight to the west?', 32185), -- Stubborn Winds
(14306, 0, 0, 0, 0, 'Have you helped to deal with the lasher problem, $c?', 32185), -- Pulling Weeds
(14246, 0, 0, 0, 0, 'Have you found homes for the swoop eggs, $c?', 32185); -- Early Adoption

UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=24518; -- The Low Road
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32185 WHERE `ID`=24514; -- Raptor Scraps
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32185 WHERE `ID`=24513; -- Eye for an Eye
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32185 WHERE `ID`=25369; -- Stinglasher
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='How goes the hunt, $n?  Are you here to report your success?', `VerifiedBuild`=32185 WHERE `ID`=25367; -- Zukk'ash Infestation
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25366; -- The Battle Plans
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32185 WHERE `ID`=25465; -- Still With The Zapped Giants
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32185 WHERE `ID`=25466; -- Even More Fuel for the Zapping
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32185 WHERE `ID`=5421; -- Fish in a Bucket
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you banished the demon portals at Mannoroc Coven?', `VerifiedBuild`=32185 WHERE `ID`=5581; -- Portals of the Legion
UPDATE `quest_request_items` SET `CompletionText`='Were you able to find our belongings, $n?', `VerifiedBuild`=32185 WHERE `ID`=14316; -- Cenarion Property
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `CompletionText`='Where\'s my ghost-o-plasm, $n?', `VerifiedBuild`=32185 WHERE `ID`=6134; -- Ghost-o-plasm Round Up
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32185 WHERE `ID`=5501; -- Bone Collector
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32185 WHERE `ID`=5561; -- Kodo Roundup
UPDATE `quest_request_items` SET `CompletionText`='How\'s the search for tail coming, $n?' WHERE `ID`=14252; -- Good Gold For Bad Tail

UPDATE `quest_request_items` SET `VerifiedBuild`=32185 WHERE `ID` IN (25423, 25422, 14339, 14325, 14304, 14305);

DELETE FROM `quest_request_items` WHERE `ID` IN (28641 /*Pride of the Dinner Table*/, 28640 /*Fresh Frostsabers*/, 28637 /*A Taste for Bear*/, 28703 /*Step Into My Barrow*/, 28842 /*Umbranse's Deliverance*/, 28841 /*The Arcane Storm Within*/, 28831 /*Damn You, Frostilicus*/, 28830 /*Chips off the Old Block*/, 28829 /*Razor Beak and Antlers Pointy*/, 28615 /*Turning the Earth*/, 28614 /*Bearzerker*/, 28519 /*Pain of the Blood Elves*/, 28513 /*Pride of the Highborne*/, 28470 /*High Chief Winterfall*/, 28460 /*Threat of the Winterfall*/, 24695 /*Ever Watching From Above*/, 24709 /*A Tale of Two Shovels*/, 24708 /*The Fossil-Finder 3000*/, 24706 /*The Spirits of Golakka Hot Springs*/, 24704 /*The Evil Dragons of Un'Goro Crater*/, 24730 /*Roll the Bones*/, 24703 /*An Important Lesson*/, 24718 /*The Mighty U'cha*/, 24926 /*Serving A-Me 01*/, 24715 /*Repairing A-Me 01*/, 24717 /*The Apes of Un'Goro*/, 24699 /*Gormashh the Glutinous*/, 24702 /*Here Lies Dadanga*/, 24736 /*Shizzle's Flyer*/, 24701 /*Marshal's Refuse*/, 24700 /*Hard to Harvest*/, 24737 /*Super Sticky*/, 24691 /*Peculiar Delicacies*/, 24692 /*The Fledgling Colossus*/, 24734 /*Lost!*/, 24690 /*Blazerunner*/, 24866 /*An Abandoned Research Camp*/, 24720 /*Crystals of Power*/, 24865 /*Is This Stuff Still Good?*/, 24740 /*Volcanic Activity*/, 24697 /*How to Make Meat Fresh Again*/, 24742 /*Finding the Source*/, 24855 /*Aberrant Flora*/, 24687 /*Bouquets of Death*/, 24733 /*The Bait for Lar'korwi*/, 24686 /*Carried on the Waves*/, 24732 /*The Scent of Lar'korwi*/, 24719 /*Claws of White*/, 24731 /*The Fare of Lar'korwi*/, 26931 /*Foxes and Hounds*/, 25006 /*The Grasp Weakens*/, 25003 /*The Family Crypt*/, 24999 /*Planting the Seed of Fear*/, 24993 /*Annihilate the Worgen*/, 24978 /*Reaping the Reapers*/, 28159 /*The Doomstone*/, 28158 /*Unbound*/, 28157 /*Four Twilight Elements*/, 28136 /*Behind You!*/, 28139 /*Codemaster's Code*/, 28127 /*Break Them Out*/, 28125 /*Something to Wear*/, 28088 /*Release Heartrazor*/, 28087 /*Death to all Trappers!*/, 28086 /*Free the Pridelings*/, 27330 /*Invoking the Serpent*/, 27328 /*Grimtotem Chiefs: The Chief of Chiefs*/, 27324 /*Grimtotem Chiefs: Grundig Darkcloud*/, 25874 /*Horn of the Traitor*/, 27319 /*Grimtotem Chiefs: Elder Stormhoof*/, 27326 /*The Drums of War*/, 27321 /*The Writ of History*/, 27317 /*The Rattle of Bones*/, 27315 /*Grimtotem Chiefs: Isha Gloomaxe*/, 27313 /*Darkcloud Grimtotem*/, 27311 /*No Weapons For You!*/, 25872 /*The Brave and the Bold*/, 25870 /*Grimtotem in the Post*/, 25826 /*Deliver the Goods*/, 25814 /*Go Blow that Horn*/, 25799 /*Defend the Drill*/, 25797 /*Eminent Domain*/, 25779 /*Fake Gold for Black Gold*/, 25775 /*Fool's Gold*/, 25762 /*The Ancient Brazier*/, 25704 /*The Mad Magus*/, 28048 /*That Smart One's Gotta Go*/, 28047 /*Freezing the Pipes*/, 28051 /*We All Scream for Ice Cream... and then Die!*/, 28045 /*The Greatest Flavor in the World!*/, 28042 /*Special Delivery for Brivelthwerp*/, 25589 /*A Little Payback*/, 25586 /*Quiet the Cannons*/, 25526 /*In the Outhouse*/, 25518 /*Bar Fight!*/, 25591 /*Thunderdrome: Grudge Match!*/, 25107 /*The Grand Tablet*/, 25070 /*What Lies Within*/, 25068 /*The Crumbling Past*/, 25017 /*Ancient Obstacles*/, 25019 /*Laying Claim*/, 25020 /*Fragments of Language*/, 25014 /*Sandscraper's Treasure*/, 25001 /*Sandscraper*/, 24963 /*Maul 'Em With Kindness*/, 24957 /*Get The Centipaarty Started*/, 24955 /*Un-Chartered*/, 24951 /*A Great Idea*/, 25072 /*A Few Good Goblins*/, 24932 /*Cutting Losses*/, 24950 /*Captain Dreadbeard*/, 25541 /*Filling Our Pockets*/, 25534 /*Going Off-Task*/, 24949 /*Booty Duty*/, 24928 /*To The Ground!*/, 24927 /*Dead Man's Chest*/, 25115 /*Blisterpaw Butchery*/, 24910 /*Rocket Rescue*/, 25111 /*Scavengers Scavenged*/, 25095 /*Thunderdrome: Sarinexx!*/, 25094 /*Thunderdrome: Zumonga!*/, 24907 /*Puddle Stomping*/, 28509 /*Warchief's Command: Tanaris!*/, 24906 /*Seaside Salvage*/, 25112 /*Butcherbot*/, 24608 /*Mangletooth*/, 24603 /*Don't Stop Bereavin'*/, 24633 /*Mahka's Plea*/, 24637 /*The Butcher of Taurajo*/, 24618 /*Claim the Battle Scar*/, 24577 /*Desolation Hold Inspection*/, 24572 /*Taking Back Taurajo*/, 24546 /*A Line in the Dirt*/, 24552 /*Lion's Pride*/, 24601 /*The Nightmare Scar*/, 24566 /*Sowing a Solution*/, 24565 /*Biological Intervention*/, 27575 /*From the Belly of the Beast*/, 27574 /*I Never Forget a Face*/, 27577 /*7th Legion Battle Plans*/, 27580 /*Sowing Discord*/, 27547 /*Of No Consequence*/, 27548 /*Lessons in Fear*/, 27550 /*Pyrewood's Fall*/, 27512 /*Transdimensional Warfare: Chapter I*/, 27510 /*A Wolf in Bear's Clothing*/, 27484 /*Only One May Enter*/, 27483 /*Practical Vengeance*/, 27478 /*Relios the Relic Keeper*/, 27476 /*Dalar Dawnweaver*/, 27475 /*Unyielding Servitors*/, 27474 /*Breaking the Barrier*/, 27406 /*A Man Named Godfrey*/, 27360 /*Vengeance for Our Soldiers*/, 27322 /*Korok the Colossus*/, 27349 /*Break in Communications: Dreadwatch Outpost*/, 27333 /*Losing Ground*/, 27181 /*Excising the Taint*/, 27099 /*No Escape*/, 27097 /*Rise, Forsaken*/, 27088 /*It's Only Poisonous if You Ingest It*/, 27093 /*Lost in the Darkness*/, 27095 /*Skitterweb Menace*/, 27069 /*Steel Thunder*/, 27073 /*Give 'em Hell!*/, 26989 /*The Gilneas Liberation Front*/, 26965 /*The Warchief Cometh*/, 28527 /*Warchief's Command: Silithus!*/, 26305 /*Saving Yenniku*/, 26362 /*Be Raptor*/, 26405 /*Zul'Mamwe Mambo*/, 26304 /*Nighttime in the Jungle*/, 26360 /*Mind Control*/, 26359 /*See Raptor*/, 26352 /*Cozzle's Plan*/, 26403 /*Venture Company Mining*/, 26400 /*The Universal Key*/, 26351 /*Mind Vision*/, 26399 /*The Mosh'Ogg Bounty*/, 26303 /*The Mind's Eye*/, 26334 /*Bloodlord Mandokir*/, 26301 /*Speaking with Nezzliok*/, 26332 /*Skullsplitter Mojo*/, 26300 /*Nezzliok Will Know*/, 26338 /*Population Con-Troll*/, 26330 /*Who's a Big Troll?*/, 26325 /*A Nose for This Sort of Thing*/, 26299 /*Headhunting*/, 26298 /*Hunt for Yenniku*/, 26407 /*Mosh'Ogg Handiwork*/, 26281 /*The Defense of Grom'gol: Trollish Thievery*/, 26321 /*I Think She's Hungry*/, 26280 /*The Defense of Grom'gol: Murloc Menace*/, 26279 /*The Defense of Grom'gol: Ogre Oppression*/, 26278 /*The Defense of Grom'gol: Raptor Risk*/, 28634 /*Extinction*/, 28643 /*The Durnholde Challenge: Zephyrus*/, 28604 /*Deception and Trickery*/, 28538 /*Cry of the Banshee*/, 28556 /*Breaking the Hand*/, 28400 /*Heroes of the Horde!*/, 28495 /*A Fighting Chance*/, 28397 /*They Will Never Expect This...*/, 28354 /*Kasha Will Fly Again*/, 28324 /*Studies in Lethality*/, 28332 /*Helcular's Command*/, 28331 /*Helcular's Rod Giveth...*/, 28235 /*Burnside Must Fall*/, 28230 /*Protocol*/, 28197 /*Discretion is Key*/, 28154 /*Muckgill's Flipper or Something...*/, 28146 /*Coastal Delicacies!*/, 28138 /*Human Infestation*/, 28096 /*Welcome to the Machine*/, 28395 /*Feathers for Nafien*/, 28364 /*The Chieftain's Key*/, 28366 /*Disarming Bears*/, 28338 /*Deadwood of the North*/, 28340 /*A Bomb Deal*/, 28339 /*Is Your Oil Running?*/, 28336 /*Slap and Cap*/, 28370 /*Wisp-napping*/, 28357 /*Take it to the Tree*/, 28334 /*A Flare Fight*/, 28333 /*It's Time to Oil Up*/, 28261 /*Deceivers In Our Midst*/, 28217 /*Wanted: The Demon Hunter*/, 28224 /*The Last Protector*/, 28221 /*These Roots Were Made For Stompin'*/, 28222 /*Singin' in the Sun*/, 28219 /*Buzzers for Baby*/, 28220 /*Seeking Soil*/, 28374 /*Weeding the Lawn*/, 28358 /*Hunting the Damned*/, 28361 /*Squirrely Clean*/, 28360 /*Running Their Course*/, 28214 /*Cleanup at Bloodvenom Post*/, 28213 /*Hazzard Disposal*/, 28190 /*The Tainted Ooze*/, 28129 /*The Demon Prince*/, 28121 /*Forces of Jaedenar*/, 28288 /*Open Their Eyes*/, 28102 /*Fight the Power*/, 28113 /*Break the Unbreakable*/, 28000 /*Do the Imp-Possible*/, 28396 /*Feathers for Grazle*/, 27994 /*Ruumbo Demands Justice*/, 27997 /*The Corruption of the Jadefire*/, 27296 /*Raze Direhorn Post!*/, 27293 /*The Grimtotem Plot*/, 27294 /*More than Coincidence*/, 27258 /*The Black Shield*/, 27415 /*The Brood of Onyxia*/, 27348 /*Secure the Cargo!*/, 27347 /*Corrosion Prevention*/, 27340 /*Direhorn Raiders*/, 27339 /*The Reagent Thief*/, 27336 /*The Grimtotem Weapon*/, 27229 /*SMASH BROODQUEEN*/, 27244 /*The Lost Report*/, 27186 /*Jarl Needs a Blade*/, 27191 /*Hungry as an Ogre!*/, 27190 /*Cleansing Witch Hill*/, 27189 /*The Witch's Bane*/, 27184 /*Jarl Needs Eyes*/, 27188 /*What's Haunting Witch Hill?*/, 27183 /*Marsh Frog Legs*/, 25292 /*Next of Kin*/, 27256 /*The Black Shield*/, 25051 /*Darkmist Extermination*/, 26682 /*A Shambling Threat*/, 27424 /*Overlord Mok'Morokk's Concern*/, 28554 /*Warchief's Command: Dustwallow Marsh!*/, 27411 /*Challenge to the Black Flight*/, 27410 /*Spirits of Stonemaul Hold*/, 27409 /*The Essence of Enmity*/, 27408 /*Banner of the Stonemaul*/, 28504 /*Warchief's Command: Thousand Needles!*/, 27412 /*WANTED: Goreclaw the Ravenous*/, 27413 /*Catch a Dragon by the Tail*/, 26703 /*Bloodsail's End*/, 26697 /*The Final Voyage of the Brashtide*/, 26695 /*Prepare for Takeoff*/, 26679 /*Return to Revilgaz*/, 26664 /*Making Mutiny*/, 26663 /*Sinking From Within*/, 26662 /*The Brashtide Crew*/, 26649 /*Drive-By Piracy*/, 26647 /*Ol' Blasty*/, 26648 /*Our Mortal Enemies*/, 26633 /*Swabbing Duty*/, 26601 /*Mok'rash the Cleaver*/, 26602 /*A Dish Best Served Huge*/, 26435 /*I'm A Huge Liar and a Fraud*/, 26604 /*Protecting Her Royal Highness Poobah*/, 26535 /*Recipe for Disaster*/, 26534 /*Let's See What You've Got, Zanzil*/, 26533 /*Zanzil's Secret*/, 26494 /*Mixmaster Jasper*/, 26550 /*Backdoor Dealings*/, 26495 /*Chabal*/, 26592 /*Diffractory Chromascope*/, 26434 /*Primal Reagents of Power*/, 26493 /*There's Somebody Out There Who Wants It*/, 26487 /*Akiris by the Bundle*/, 26433 /*The Holy Water of Clarity*/, 26489 /*It's You!!*/, 26450 /*If They're Just Going to Leave Them Lying Around...*/, 14476 /*Rigged to Blow*/, 14464 /*Lightning Strike Assassination*/, 24433 /*Let Them Feast on Fear*/, 14261 /*Ice Cold*/, 14297 /*Pro-liberation*/, 24467 /*Fade to Black*/, 14390 /*Easy is Boring*/, 24479 /*The Trial of Shadow*/, 24478 /*The Trial of Frost*/, 14300 /*The Trial of Fire*/, 14296 /*Watch Your Step*/, 14435 /*The Blackmaw Doublecross*/, 14433 /*Diplomacy by Another Means*/, 14432 /*A Pale Brew*/, 14226 /*Trouble Under Foot*/, 14230 /*Manual Labor*/, 14429 /*Arcane De-Construction*/, 14428 /*Amberwind's Journal*/, 14263 /*Waste of Thyme*/, 14249 /*Shear Will*/, 14250 /*Renewable Resource*/, 14340 /*Dressed to Impress*/, 14431 /*The Blackmaw Scar*/, 14324 /*Full of Hot Water*/, 14323 /*Absorbent*/, 14132 /*That's Just Rude!*/, 14131 /*A Little Pick-me-up*/, 24449 /*Shore Leave*/, 14486 /*Handling the Goods*/, 14485 /*Ticker Required*/, 14484 /*Head of the Snake*/, 14480 /*Extermination*/, 14487 /*Still Beating Heart*/, 24436 /*Halo Drops*/, 24435 /*Mop Up*/, 24437 /*First Come, First Served*/, 24458 /*A Hello to Arms*/, 14295 /*Sisters of the Sea*/, 14270 /*The Keystone Shard*/, 14388 /*Azsharite Experiment Number Two*/, 14383 /*The Terrible Tinkers of the Ruined Reaches*/, 14377 /*Befriending Giants*/, 14262 /*To Gut a Fish*/, 14422 /*Raptor Raptor Rocket*/, 14322 /*Bad Science! Bad!*/, 14216 /*Mystery of the Sarcen Stone*/, 14423 /*Dozercism*/, 14215 /*Memories of the Dead*/, 14209 /*Gunk in the Trunk*/, 14202 /*Survey the Lakeshore*/, 14201 /*A Thousand Stories in the Sand*/, 24452 /*Profitability Scouting*/, 14472 /*In The Face!*/, 14471 /*First Degree Mortar*/, 14470 /*Military Breakthrough*/, 14469 /*Hand-me-downs*/, 14194 /*Refleshification*/, 14192 /*Prismbreak*/, 14190 /*The Perfect Prism*/, 14165 /*Stone Cold*/, 14161 /*Basilisk Bashin'*/, 14117 /*The Eyes of Ashenvale*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(28641, 0, 0, 0, 0, 'Stopping by to chat?', 32305), -- Pride of the Dinner Table
(28640, 0, 0, 0, 0, 'Those frostsabers aren\'t going to kill, skin, and smoke themselves!', 32305), -- Fresh Frostsabers
(28637, 0, 0, 0, 0, 'Don\'t wander too far to the south. The Captain will follow you there later.', 32305), -- A Taste for Bear
(28703, 0, 0, 0, 0, 'I figured a talented $c like you would have no problem taking care of a few bugs.$b$bI GUESS I FIGURED WRONG.', 32305), -- Step Into My Barrow
(28842, 0, 0, 0, 0, 'You must finish this for me, $n.', 32305), -- Umbranse's Deliverance
(28841, 0, 0, 0, 0, 'I\'m counting on you, $n.', 32305), -- The Arcane Storm Within
(28831, 0, 0, 0, 0, 'Will this torment never end?', 32305), -- Damn You, Frostilicus
(28830, 0, 0, 0, 0, 'I fear I will die on this snowbank, $c.', 32305), -- Chips off the Old Block
(28829, 0, 0, 0, 0, 'They came at me two at a time, $c.  I stood no chance.', 32305), -- Razor Beak and Antlers Pointy
(28615, 0, 1, 0, 0, 'Have the totems been destroyed?', 32305), -- Turning the Earth
(28614, 0, 6, 0, 0, 'Has Grolnar fallen?', 32305), -- Bearzerker
(28519, 0, 0, 0, 0, 'Do not loiter too long. There are few escapes from Kel\'theril.', 32305), -- Pain of the Blood Elves
(28513, 0, 0, 0, 0, 'Death is not always a relief.', 32305), -- Pride of the Highborne
(28470, 0, 1, 0, 0, 'Maybe you will find out more in Winterfall Village, $n.', 32305), -- High Chief Winterfall
(28460, 0, 0, 0, 0, 'I appreciate your help!', 32305), -- Threat of the Winterfall
(24695, 0, 0, 0, 0, 'You have not yet completed my gauntlet, $n.', 32305), -- Ever Watching From Above
(24709, 0, 0, 0, 0, 'Is the deed done?  Did you manage to salvage his notes?', 32305), -- A Tale of Two Shovels
(24708, 0, 0, 0, 0, 'Have you found anything?  Did it work?', 32305), -- The Fossil-Finder 3000
(24706, 0, 0, 0, 0, 'We have not completed our prayers.  Shall I join you?', 32305), -- The Spirits of Golakka Hot Springs
(24704, 0, 0, 0, 0, 'I\'ve not yet meted enough justice, squire.  You may complain to me only when 15 of the beasts are slayed.', 32305), -- The Evil Dragons of Un'Goro Crater
(24730, 1, 1, 0, 0, 'Think whatever you want of me, but they\'re not going to care if the bones they get to research are from ancient stegodons and diemetradons or the ones that almost devoured us wholesale when we were trying to set up our camps.  I\'ll just be happy if we get out of here alive...', 32305), -- Roll the Bones
(24703, 0, 0, 0, 0, 'Your first quest is a simple one, yet it somehow remains unfinished.  Endure my words and become my squire.', 32305), -- An Important Lesson
(24718, 1, 0, 0, 0, 'Red fur?  What\'re you waiting for!  Go back and get that red gorilla!  I\'ll pay you double!', 0), -- The Mighty U'cha
(24926, 6, 0, 0, 0, 'Wh... what\'s this?', 0), -- Serving A-Me 01
(24715, 0, 0, 0, 0, '<A-Me 01 has gone into power save mode.>', 32305), -- Repairing A-Me 01
(24717, 2, 2, 0, 0, 'I never know what style is in vogue, so I\'ll want a few different colors.  Try to get hides from each different type of gorilla there.', 32305), -- The Apes of Un'Goro
(24699, 0, 0, 0, 0, 'I\'m counting on you, $n.  I\'m invested pretty heavily into this \"tar as glue\" scheme, and it\'d be a shame if you came back empty-handed.', 32305), -- Gormashh the Glutinous
(24702, 0, 0, 0, 0, 'Sturdy mount and trusted friend.$b$bDied shortly after the Cataclysm.  She always hated loud noises.$b$bIn lieu of flowers, please drop off a few Bloodpetal sprouts.  In life, she loved nothing more.', 0), -- Here Lies Dadanga
(24736, 1, 1, 0, 0, 'Every great vehicle needs a name... I was thinking I\'d call it... Pwned!', 32305), -- Shizzle's Flyer
(24701, 0, 0, 0, 0, 'Did you find anything good?', 32305), -- Marshal's Refuse
(24700, 0, 0, 0, 0, 'Have you obtained the tarblossoms yet?  I don\'t see them...', 32305), -- Hard to Harvest
(24737, 4, 4, 0, 0, 'Tara\'s done it again -- this super sticky glue will be all the rage!', 32305), -- Super Sticky
(24691, 0, 0, 0, 0, 'I need a lot of them because I\'ve got to pay for shipping, handling, marketing... oh, and I\'ve got to pay you as well.', 32305), -- Peculiar Delicacies
(24692, 0, 0, 0, 0, 'The colossus is a fearsome beast, $n.  By all means, if it starts to do anything suspicious, get out of its way!', 32305), -- The Fledgling Colossus
(24734, 0, 0, 0, 0, 'Ringo\'s sack rests on the rock in front of you.', 0), -- Lost!
(24690, 0, 0, 0, 0, 'Please, $n.  Head up to the top of Fire Plume Ridge and show Blazerunner an early retirement.', 32305), -- Blazerunner
(24866, 0, 0, 0, 0, 'Yes, $n?', 0), -- An Abandoned Research Camp
(24720, 5, 5, 0, 0, 'I just know I\'m onto something here, $n!', 32305), -- Crystals of Power
(24865, 0, 0, 0, 0, 'What have you got there?', 0), -- Is This Stuff Still Good?
(24740, 6, 6, 0, 0, 'Do you think the volcano is active?  I wonder why it didn\'t explode when the cataclysm hit.', 32305), -- Volcanic Activity
(24697, 0, 0, 0, 0, 'Throw the meat, then let the dinosaurs chase you into the pit.  Easy as that!', 32305), -- How to Make Meat Fresh Again
(24742, 1, 1, 0, 0, 'I\'d go there myself, but... I\'m a little scared of the fire elementals there!', 32305), -- Finding the Source
(24855, 0, 0, 0, 0, 'We cannot move forward until you have put an end to the bloodpetals, $c.', 32305), -- Aberrant Flora
(24687, 0, 0, 0, 0, 'Remember the tale of Archimonde, $c.  The young lashers are much weaker than you, but they can still overrun you with their numbers.', 32305), -- Bouquets of Death
(24733, 2, 2, 0, 0, 'Do not let fear overpower you, $n. Fear is the great betrayer... you must remain strong!', 32305), -- The Bait for Lar'korwi
(24686, 0, 0, 0, 0, 'Have you obtained the seeds yet?', 32305), -- Carried on the Waves
(24732, 1, 1, 0, 0, 'Be careful, $n. Getting close to any nest of eggs surely will provoke the mothers... even if you\'ve already secured a gland from one. The mothers can be just as deadly as Lar\'korwi himself when they fight to protect their young. But, if you are successful, then we shall have a definitive way of bringing Lar\'korwi out from hiding.', 32305), -- The Scent of Lar'korwi
(24719, 6, 6, 0, 0, 'Have you gotten any of the claws yet?', 32305), -- Claws of White
(24731, 1, 1, 0, 0, 'Do not take my words lightly, $n. If you truly wish to face this creature, then you must be careful... and smart. It will take a great deal of strength and insight to draw out Lar\'korwi and defeat him.', 32305), -- The Fare of Lar'korwi
(26931, 0, 0, 0, 0, 'The Dark Lady will not tolerate the living.', 32305), -- Foxes and Hounds
(25006, 0, 6, 0, 0, 'What did you find out?', 32305), -- The Grasp Weakens
(25003, 0, 0, 0, 0, 'Time is not a luxury we have, $n.  With each passing hour, the Scourge\'s hold on Tirisfal Glades grows more firm.', 32305), -- The Family Crypt
(24999, 0, 0, 0, 0, 'Chase them until they pass out in fear, $n.  Let them grow up in fear of the Forsaken.', 32305), -- Planting the Seed of Fear
(24993, 0, 0, 0, 0, 'By Sylvanas, these wolf-men will NOT undo the progress we\'ve made!', 32305), -- Annihilate the Worgen
(24978, 0, 0, 0, 0, 'You\'ve not yet completed my task, $n.  It is time for the harvesters to become the harvested!', 32305), -- Reaping the Reapers
(28159, 6, 6, 0, 0, 'Do you have the Doomstone, $c?', 32305), -- The Doomstone
(28158, 0, 15, 0, 0, 'Both the Fury and the Vortex must be unbound! Do you want to be responsible for the deaths of thousands?!$B$BI do not suffer fools gladly, $n. Complete this simple task!', 32305), -- Unbound
(28157, 6, 6, 0, 0, 'Do you have all of the elements, $c?', 32305), -- Four Twilight Elements
(28136, 0, 25, 0, 0, 'You\'ll have to deal with all three of them if the Twilight Bulwark is to be neutralized.', 32305), -- Behind You!
(28139, 6, 6, 0, 0, 'Do you have the codes to the Elder Crone\'s bonds?', 32305), -- Codemaster's Code
(28127, 0, 1, 0, 0, 'There are still more prisoners, $n.', 32305), -- Break Them Out
(28125, 6, 6, 0, 0, 'How much of that armor have you collected?$B$BYou\'re going to want to be well disguised for the next thing that you\'re going to have to do.', 32305), -- Something to Wear
(28088, 0, 5, 0, 0, 'You must free Heartrazor before they cart him off to their evil base!', 32305), -- Release Heartrazor
(28087, 6, 6, 0, 0, 'What insanity could drive someone to do such horrible things?', 32305), -- Death to all Trappers!
(28086, 0, 6, 0, 0, '$n, would you please free more of the pridelings? I\'d hate to see them enslaved to the Twilight\'s Hammer, or worse.', 32305), -- Free the Pridelings
(27330, 0, 1, 0, 0, 'Only by subduing Arikara will you discover where Magatha Grimtotem is hiding.', 32305), -- Invoking the Serpent
(27328, 0, 1, 0, 0, 'Arnak must fall, $n, if we are to win the battle against the Grimtotem.', 32305), -- Grimtotem Chiefs: The Chief of Chiefs
(27324, 0, 1, 0, 0, '$n, we must find and kill Grundig Darkcloud.', 32305), -- Grimtotem Chiefs: Grundig Darkcloud
(25874, 6, 0, 0, 0, '$n? What news do you have?', 0), -- Horn of the Traitor
(27319, 0, 1, 0, 0, 'We must kill Elder Stormhoof before we deal with the rest of the Grimtotem chiefs.', 32305), -- Grimtotem Chiefs: Elder Stormhoof
(27326, 274, 274, 0, 0, 'War is not an activity to engage in for those who are faithful to the Earth Mother\'s teachings.', 32305), -- The Drums of War
(27321, 1, 1, 0, 0, 'We will need the actual writ, and not just any scroll hanging.', 32305), -- The Writ of History
(27317, 0, 0, 0, 0, 'The fabled Rattle of Bones, $n!', 0), -- The Rattle of Bones
(27315, 0, 1, 0, 0, 'The Gloomaxe must be slain if we are to effectively reduce the might of the Grimtotem attack on Freewind Post.', 32305), -- Grimtotem Chiefs: Isha Gloomaxe
(27313, 0, 1, 0, 0, 'We need to kill more of the Grimtotem, $n.', 32305), -- Darkcloud Grimtotem
(27311, 0, 1, 0, 0, 'We shall have to burn more of their weapon racks than that if we are to put a dent in their ability to fight.', 32305), -- No Weapons For You!
(25872, 0, 6, 0, 0, 'Where\'s our brave? Is he alive?', 32305), -- The Brave and the Bold
(25870, 0, 5, 0, 0, 'If we\'re to going to push back these Grimtotem mongrels, you\'re going to have to kill more of them than that, $c!', 32305), -- Grimtotem in the Post
(25826, 6, 0, 0, 0, 'Hello again, friend. Is that oil?!', 0), -- Deliver the Goods
(25814, 0, 1, 0, 0, 'It\'s simple really... you blow the horn, their elemental leader shows up, and you kill it.', 32305), -- Go Blow that Horn
(25799, 0, 6, 0, 0, 'How much oil did you get?', 32305), -- Defend the Drill
(25797, 0, 5, 0, 0, 'We\'ll never take over the Heights unless you kill those centaur!', 32305), -- Eminent Domain
(25779, 33, 0, 0, 0, 'What\'s this? That is a lot of gold you have there.', 0), -- Fake Gold for Black Gold
(25775, 1, 1, 0, 0, 'Once you return with enough of that pyrite, we\'ll give it a once over with a paint brush, pile it all up on a pallet, and send you back up with it to the chieftain.', 32305), -- Fool's Gold
(25762, 33, 33, 0, 0, 'You have the Sacred Flame? Do not speak to me unless you do, $r!', 32305), -- The Ancient Brazier
(25704, 0, 1, 0, 0, 'Ya gotta use the stick on Tirth\'s corpse if ya gonna help, $n.', 32305), -- The Mad Magus
(28048, 0, 5, 0, 0, '$n! Get down there and kill that thing!', 32305), -- That Smart One's Gotta Go
(28047, 0, 1, 0, 0, 'There are four main pipes already setup in the cave. I need you to freeze each of them so that the refrigerant can start flowing.', 32305), -- Freezing the Pipes
(28051, 0, 6, 0, 0, 'Could you hook a few more of their bodies for me?', 32305), -- We All Scream for Ice Cream... and then Die!
(28045, 6, 6, 0, 0, 'You got enough bug goo for the first batch?', 32305), -- The Greatest Flavor in the World!
(28042, 6, 0, 0, 0, 'That\'s not what I think it is? Is it?!', 0), -- Special Delivery for Brivelthwerp
(25589, 0, 0, 0, 0, 'Maybe you could exact just a little more payback on those no-good Southea pirates?', 32305), -- A Little Payback
(25586, 0, 5, 0, 0, '$n, you gotta quiet a few more of those cannons or we don\'t stand a chance!\n', 32305), -- Quiet the Cannons
(25526, 0, 0, 0, 0, 'Oh, for the love of profit, do you have that crowbar yet? Drowning here!', 32305), -- In the Outhouse
(25518, 0, 5, 0, 0, 'What? Are you deaf?$B$BYou need to go start that bar fight... now!', 32305), -- Bar Fight!
(25591, 0, 1, 0, 0, 'Stop wasting my time. Enter and fight!', 32305), -- Thunderdrome: Grudge Match!
(25107, 0, 0, 0, 0, 'You\'re back! What have you found?', 0), -- The Grand Tablet
(25070, 0, 0, 0, 0, 'The chest\'s lid does not budge.', 32305), -- What Lies Within
(25068, 0, 0, 0, 0, 'Handle those carefully, $n; they are as ancient as the world itself.', 32305), -- The Crumbling Past
(25017, 0, 0, 0, 0, 'Too many golems still wander the sand, $n.', 32305), -- Ancient Obstacles
(25019, 0, 0, 0, 0, 'The dwarves will not be dissuaded by weak resistance, $n.', 32305), -- Laying Claim
(25020, 0, 0, 0, 0, 'Do you have the tablets?', 32305), -- Fragments of Language
(25014, 0, 0, 0, 0, 'Find something?', 0), -- Sandscraper's Treasure
(25001, 0, 0, 0, 0, 'Let\'s save the chit-chat and whatever else for when we\'re off the clock here, okay?', 32305), -- Sandscraper
(24963, 0, 0, 0, 0, 'Keep at it, babe. I can see \'em from here, don\'t get lazy on me.', 32305), -- Maul 'Em With Kindness
(24957, 1, 1, 0, 0, 'Have you got enough? These ogres don\'t look like the type to like small portions.', 32305), -- Get The Centipaarty Started
(24955, 0, 0, 0, 0, 'Babe, there\'s still blank spots on this sheet. Being near ogres isn\'t rubbing off on your intelligence, I hope.', 32305), -- Un-Chartered
(24951, 0, 0, 0, 0, 'I don\'t see any bug with you, pal.', 32305), -- A Great Idea
(25072, 0, 0, 0, 0, 'This camp is still feelin\' pretty lonely. Mind savin\' a few more?', 32305), -- A Few Good Goblins
(24932, 0, 0, 0, 0, 'There\'s still plenty of those things out there, pal. Keep at it!', 32305), -- Cutting Losses
(24950, 0, 0, 0, 0, 'I\'m flattered that you\'d rather stay here and flirt with me than go kill that pirate captain. So flattered that I might not fire you if you get going right now and do it already.', 32305), -- Captain Dreadbeard
(25541, 0, 0, 0, 0, 'Don\'t get squeamish on me now.', 32305), -- Filling Our Pockets
(25534, 0, 0, 0, 0, 'What\'s wrong? Scared of a few cannonballs?', 32305), -- Going Off-Task
(24949, 0, 0, 0, 0, 'Let\'s see what you\'ve got. You\'re not hiding any for yourself, are you? You\'ll never find a buyer without me, you know.', 32305), -- Booty Duty
(24928, 0, 0, 0, 0, 'What part of \"to the ground\" don\'t you understand, $c?', 32305), -- To The Ground!
(24927, 0, 0, 0, 0, 'Look, if you think the bare minimum is enough, then ok. But some people choose to kill more pirates and I encourage that, ok?$B$BAnd by \"ok\", I mean \"go kill more and stop wasting my time\".', 32305), -- Dead Man's Chest
(25115, 0, 0, 0, 0, 'Got enough?', 32305), -- Blisterpaw Butchery
(24910, 0, 0, 0, 0, 'What\'s with the premature bail-out? We gotta get back out there.', 32305), -- Rocket Rescue
(25111, 0, 0, 0, 0, 'Are you done? I don\'t want fire roc gizzards left sitting in Butcherbot\'s tank for too long, it\'s harsh on the machinery.', 32305), -- Scavengers Scavenged
(25095, 0, 274, 0, 0, 'Stop wasting my time. Enter and fight!', 32305), -- Thunderdrome: Sarinexx!
(25094, 0, 5, 0, 0, 'Stop wasting my time. Enter and fight!', 32305), -- Thunderdrome: Zumonga!
(24907, 0, 1, 0, 0, 'You\'re under quota. Clear out more of the sea giants.', 32305), -- Puddle Stomping
(28509, 0, 5, 0, 0, 'It\'s about time!', 32305), -- Warchief's Command: Tanaris!
(24906, 0, 0, 0, 0, 'Let\'s see what you\'ve got.', 32305), -- Seaside Salvage
(25112, 0, 0, 0, 0, 'You\'ll need to fill the little bot\'s hopper up completely.', 32305), -- Butcherbot
(24608, 0, 0, 0, 0, 'Is he dead?', 32305), -- Mangletooth
(24603, 0, 0, 0, 0, 'More!  Kill more of them!  MORE!', 32305), -- Don't Stop Bereavin'
(24633, 0, 0, 0, 0, 'I am sorry to ask this of you, but I want him to come here. He needs to leave that place of death...', 32305), -- Mahka's Plea
(24637, 0, 5, 0, 0, '<Bloodhilt roars impatiently.>$B$BIs the deed done? Tell me! What news?', 32305), -- The Butcher of Taurajo
(24618, 0, 0, 0, 0, 'Have you pushed them all the way back to their gates?', 32305), -- Claim the Battle Scar
(24577, 0, 6, 0, 0, 'What is this about? Why are you creating such a commotion in my camp?', 32305), -- Desolation Hold Inspection
(24572, 0, 6, 0, 0, 'Have you cleared out Taurajo?$B$BKilling those vultures is but a taste of the vengeance I plan to reap on these Theramore scum.', 32305), -- Taking Back Taurajo
(24546, 0, 6, 0, 0, 'Is the Alliance putting up a fight? How goes the battle for the Barrens?', 32305), -- A Line in the Dirt
(24552, 0, 1, 0, 0, 'The Barrens is a harsh land, but I have come to love it. How are you faring?', 32305), -- Lion's Pride
(24601, 0, 0, 0, 0, 'We must not allow the nightmare to spread further into our world!', 32305), -- The Nightmare Scar
(24566, 0, 0, 0, 0, 'Did it work?', 32305), -- Sowing a Solution
(24565, 0, 0, 0, 0, 'This is a necessary task, $n, and I ask that you ensure enough are slain to prevent their spread.', 32305), -- Biological Intervention
(27575, 273, 0, 0, 0, 'At the very least we\'ll have some crocolisk hides to make fancy shoes out of.', 0), -- From the Belly of the Beast
(27574, 5, 0, 0, 0, 'I never forget a face!', 0), -- I Never Forget a Face
(27577, 5, 5, 0, 0, 'Search every filthy dwarven corpse.', 32305), -- 7th Legion Battle Plans
(27580, 0, 1, 0, 0, 'Marstone is a decorated field general. He will not go down easy.', 32305), -- Sowing Discord
(27547, 0, 1, 0, 0, 'The sooner we rescue survivors the sooner we can burn down the whole of Pyrewood.', 32305), -- Of No Consequence
(27548, 0, 5, 0, 0, 'Pyrewood Village must be reduced to ashes and our enemies slain!', 32305), -- Lessons in Fear
(27550, 0, 274, 0, 0, 'I feel no remorse.', 32305), -- Pyrewood's Fall
(27512, 0, 0, 0, 0, '<The portal hums.>', 0), -- Transdimensional Warfare: Chapter I
(27510, 0, 6, 0, 0, 'Have you killed the \"bears?\"', 32305), -- A Wolf in Bear's Clothing
(27484, 6, 0, 0, 0, 'What have you learned?', 0), -- Only One May Enter
(27483, 0, 5, 0, 0, 'The people of Dalaran must suffer for what they did to me!', 32305), -- Practical Vengeance
(27478, 6, 6, 0, 0, 'Did you recover a Dalaran Archmage\'s Signet Ring?', 32305), -- Relios the Relic Keeper
(27476, 6, 0, 0, 0, 'Yes? What is it?', 0), -- Dalar Dawnweaver
(27475, 457, 457, 0, 0, 'Have you recovered the servitor cores?', 32305), -- Unyielding Servitors
(27474, 6, 6, 0, 0, 'Have you found anything yet?', 32305), -- Breaking the Barrier
(27406, 0, 5, 0, 0, 'Lord Vincent Godfrey. The name itself evokes feelings of dread in the hearts of worgen.', 32305), -- A Man Named Godfrey
(27360, 0, 0, 0, 0, 'The 7th Legion must pay for what they did!', 32305), -- Vengeance for Our Soldiers
(27322, 6, 0, 0, 0, 'Korok is dead?', 0), -- Korok the Colossus
(27349, 0, 0, 0, 0, 'Status?', 32305), -- Break in Communications: Dreadwatch Outpost
(27333, 0, 25, 0, 0, 'Kill the rebels!', 32305), -- Losing Ground
(27181, 0, 0, 0, 0, 'You found the ambushers?', 32305), -- Excising the Taint
(27099, 0, 6, 0, 0, 'What have you to report?', 32305), -- No Escape
(27097, 0, 0, 0, 0, 'Victory!', 32305), -- Rise, Forsaken
(27088, 0, 6, 0, 0, 'Have you dealt with the ettin?', 32305), -- It's Only Poisonous if You Ingest It
(27093, 0, 0, 0, 0, 'Thankfully we\'re almost out of ale.', 32305), -- Lost in the Darkness
(27095, 0, 0, 0, 0, 'The matriarch must be found!', 32305), -- Skitterweb Menace
(27069, 0, 0, 0, 0, 'The pups might be the only orcs not drunk at this base.', 32305), -- Steel Thunder
(27073, 0, 15, 0, 0, 'Give \'em hell, $r!', 32305), -- Give 'em Hell!
(26989, 0, 6, 0, 0, 'What have you to report, $nnub?', 32305), -- The Gilneas Liberation Front
(26965, 0, 5, 0, 0, 'Stand at attention, $nnub!', 32305), -- The Warchief Cometh
(28527, 0, 25, 0, 0, 'You look like help.', 32305), -- Warchief's Command: Silithus!
(26305, 0, 0, 0, 0, '$n.  Kin\'weelay told me you set out to capture Yenniku.$B$BIs it true?  Do you have him?', 0), -- Saving Yenniku
(26362, 0, 0, 0, 0, 'Where is $n\'aka?', 32305), -- Be Raptor
(26405, 0, 0, 0, 0, 'Zul\'Mamwe, though ruined, is still a defensible stronghold.  Take heed, $r.', 32305), -- Zul'Mamwe Mambo
(26304, 0, 0, 0, 0, 'Please, $n... put out the awful fires.', 32305), -- Nighttime in the Jungle
(26360, 0, 0, 0, 0, 'Extra-big spells need extra-big brains, yes.', 32305), -- Mind Control
(26359, 0, 0, 0, 0, 'Your vision not Ohgan\'aka\'s, no.$b$bYou are not ready.', 32305), -- See Raptor
(26352, 1, 1, 0, 0, 'The Venture Company\'s acts against Stranglethorn cannot be forgiven.', 32305), -- Cozzle's Plan
(26403, 0, 0, 0, 0, 'Do you have those crystals??  I need them!!$B$BI mean...I need to know the evil Venture Company is losing ground in Stranglethorn.  Because, you know, we honest folk have to make a living!', 32305), -- Venture Company Mining
(26400, 1, 1, 0, 0, 'You get that chest open yet?  I can\'t wait to see what\'s inside.', 32305), -- The Universal Key
(26351, 0, 0, 0, 0, 'Raptor named Ohgan\'aka, still your friend.', 32305), -- Mind Vision
(26399, 1, 1, 0, 0, 'Why is it that the OGRES always find the priceless artifacts?', 32305), -- The Mosh'Ogg Bounty
(26303, 0, 0, 0, 0, 'Greetings, $n.  The spirits sing praise of your bravery, yet they tell me no tales of your quest against Mai\'Zoth.$B$BDo you have the Eye?', 32305), -- The Mind's Eye
(26334, 0, 0, 0, 0, 'All I ask is the raptor, $r.  Give it to me, and the troll lives.', 0), -- Bloodlord Mandokir
(26301, 0, 0, 0, 0, 'I await the skulls...', 32305), -- Speaking with Nezzliok
(26332, 0, 0, 0, 0, '<The large troll skull floats around within the cauldron.>', 32305), -- Skullsplitter Mojo
(26300, 0, 0, 0, 0, 'The greenish broth within the cauldron bubbles.', 0), -- Nezzliok Will Know
(26338, 0, 0, 0, 0, 'We appreciate what you\'re doing for us here in Grom\'gol, $n.', 32305), -- Population Con-Troll
(26330, 0, 0, 0, 0, '<You hear the skull\'s voice:>$b$bGan\'zulah...', 32305), -- Who's a Big Troll?
(26325, 0, 0, 0, 0, '<The large troll skull bubbles to the surface.>$b$bHow many did you find?', 32305), -- A Nose for This Sort of Thing
(26299, 0, 0, 0, 0, '$n.  I fear for our chief\'s son.  Do you have the shrunken heads so I may inspect them?', 32305), -- Headhunting
(26298, 0, 0, 0, 0, '$C.  Show me you have made prey of the Bloodscalp tribe.$B$BShow me your trophies.', 32305), -- Hunt for Yenniku
(26407, 0, 0, 0, 0, 'A hand, you say?', 0), -- Mosh'Ogg Handiwork
(26281, 0, 0, 0, 0, 'Pity has no place under my command.  The trolls can find food elsewhere.  It\'s a big jungle.', 32305), -- The Defense of Grom'gol: Trollish Thievery
(26321, 0, 0, 0, 0, 'She\'s still looking a little scrawny, $n.  Maybe some more murloc meat is in order.', 32305), -- I Think She's Hungry
(26280, 0, 0, 0, 0, 'Beware the murloc fighter, $n.  In my experience his size usually belies his strength.', 32305), -- The Defense of Grom'gol: Murloc Menace
(26279, 0, 0, 0, 0, 'I need Mizjah to be cleaned of ogres, $n.  Now get to it!', 32305), -- The Defense of Grom'gol: Ogre Oppression
(26278, 0, 0, 0, 0, 'I start you out with the simplest task for a reason, $n.  Do not fail me.', 32305), -- The Defense of Grom'gol: Raptor Risk
(28634, 0, 5, 0, 0, 'Nothing less than extinction will be accepted!', 32305), -- Extinction
(28643, 0, 0, 0, 0, '', 32305), -- The Durnholde Challenge: Zephyrus
(28604, 0, 0, 0, 0, 'Deception and trickery - these are your tools!', 32305), -- Deception and Trickery
(28538, 0, 0, 0, 0, '<Melisara\'s thoughts intermingle with your thoughts.>', 32305), -- Cry of the Banshee
(28556, 0, 6, 0, 0, 'Have you planted the pocket-nukes?', 32305), -- Breaking the Hand
(28400, 0, 0, 0, 0, '<High Warlord Cromush looks somber.>', 0), -- Heroes of the Horde!
(28495, 0, 6, 0, 0, 'So... did it work?', 32305), -- A Fighting Chance
(28397, 0, 5, 0, 0, 'We will kill them all!', 32305), -- They Will Never Expect This...
(28354, 6, 6, 0, 0, 'Have you recovered the mudsnout?', 32305), -- Kasha Will Fly Again
(28324, 0, 5, 0, 0, 'We need Southshore move in ready!', 32305), -- Studies in Lethality
(28332, 0, 6, 0, 0, 'Have you dealt with the worgen?', 32305), -- Helcular's Command
(28331, 0, 25, 0, 0, 'I want that rod back when you\'re done.', 32305), -- Helcular's Rod Giveth...
(28235, 0, 274, 0, 0, 'Do not waste my time, $n.', 32305), -- Burnside Must Fall
(28230, 0, 274, 0, 0, 'Do not waste my time, $n.', 32305), -- Protocol
(28197, 0, 5, 0, 0, 'Kill the beasts! We can\'t have a rampaging geist and skeleton wandering the countryside!', 32305), -- Discretion is Key
(28154, 6, 0, 0, 0, 'Do I look like some kind of murloc scientist?', 0), -- Muckgill's Flipper or Something...
(28146, 0, 0, 0, 0, 'Have you fed my spider?', 32305), -- Coastal Delicacies!
(28138, 0, 5, 0, 0, 'We mustn\'t keep the warden waiting!', 32305), -- Human Infestation
(28096, 0, 6, 0, 0, 'How\'s the \"desk job\" coming?', 32305), -- Welcome to the Machine
(28395, 0, 1, 0, 0, 'While you have proven yourself to me, you may need to continue to work toward proving yourself to the suspicious brethren of my tribe.  To that end, I may be able to continue assisting you.$B$BSome of the Deadwood furbolgs wear a distinctive headdress that may be used as a means of proof in thinning their numbers.  Bring me a feather from any headdresses you acquire; for every set of five you bring me, you will earn recognition amongst the Timbermaw.', 0), -- Feathers for Nafien
(28364, 0, 0, 0, 0, 'Did you get the key?', 32305), -- The Chieftain's Key
(28366, 0, 0, 0, 0, 'Do you have the weapons?', 32305), -- Disarming Bears
(28338, 0, 0, 0, 0, 'Once you gain the trust of the Timbermaw, I am confident there will be something we will be able to do for you.  The Timbermaw do not forget their allies, especially in dark times such as these.', 32305), -- Deadwood of the North
(28340, 0, 0, 0, 0, 'We had a deal, right? Right?', 32305), -- A Bomb Deal
(28339, 25, 25, 0, 0, 'That stuff better not still be moving when you bring it back here.', 32305), -- Is Your Oil Running?
(28336, 0, 6, 0, 0, 'Are you in a panic too? Keep standing around here confused and I\'ll give you my own cure for that.', 32305), -- Slap and Cap
(28370, 0, 6, 0, 0, 'Did it work? Are they still in the jar?', 32305), -- Wisp-napping
(28357, 0, 1, 0, 0, 'You go on now, I\'ve got important strategizing and economy management to do.', 32305), -- Take it to the Tree
(28334, 0, 25, 0, 0, 'Careful with those flares now, don\'t want any workplace incidents.', 32305), -- A Flare Fight
(28333, 0, 6, 0, 0, 'So why are you sticking around here wasting my time?', 32305), -- It's Time to Oil Up
(28261, 0, 0, 0, 0, 'Don\'t tell me you would leave the demons to walk among us unopposed?', 32305), -- Deceivers In Our Midst
(28217, 0, 0, 0, 0, 'So they sent another?', 32305), -- Wanted: The Demon Hunter
(28224, 0, 0, 0, 0, 'All that is cut will regrow in time; the spirits endure.', 32305), -- The Last Protector
(28221, 0, 0, 0, 0, 'Help the poor trees!', 32305), -- These Roots Were Made For Stompin'
(28222, 0, 0, 0, 0, 'More sun!', 32305), -- Singin' in the Sun
(28219, 0, 0, 0, 0, 'Hungry!', 32305), -- Buzzers for Baby
(28220, 0, 0, 0, 0, '', 32305), -- Seeking Soil
(28374, 0, 0, 0, 0, 'Checking the lashers will really help me here.', 32305), -- Weeding the Lawn
(28358, 0, 0, 0, 0, 'Have you slain many infernals?', 32305), -- Hunting the Damned
(28361, 0, 0, 0, 0, 'Don\'t be shy now! Just grab them and scrub them real good.', 32305), -- Squirrely Clean
(28360, 0, 0, 0, 0, 'I wish I could bring myself to help the poor things. It\'s just so sad.', 32305), -- Running Their Course
(28214, 0, 0, 0, 0, 'I said... I said GO! Huuurgh...', 32305), -- Cleanup at Bloodvenom Post
(28213, 0, 0, 0, 0, 'Did it work?', 32305), -- Hazzard Disposal
(28190, 0, 0, 0, 0, 'The very thought of those disgusting creatures sickens me! Urgh...', 32305), -- The Tainted Ooze
(28129, 0, 0, 0, 0, 'Xavalis lurks in Shadow Hold in Jaedenar.', 32305), -- The Demon Prince
(28121, 0, 6, 0, 0, 'How goes your fight, $n? I know the shedding of blood as proof of honor can be disgusting to some, but it must be done if this land is to heal.', 32305), -- Forces of Jaedenar
(28288, 0, 0, 0, 0, 'Having fun?', 32305), -- Open Their Eyes
(28102, 0, 1, 0, 0, 'I believe in you, $n.', 32305), -- Fight the Power
(28113, 0, 0, 0, 0, 'Has Xavathras fallen?', 32305), -- Break the Unbreakable
(28000, 0, 0, 0, 0, 'Do you have an imp for me?', 32305), -- Do the Imp-Possible
(28396, 0, 1, 0, 0, 'While you have proven yourself to me, you may need to continue to work toward proving yourself to the suspicious brethren of my tribe.  To that end, I may be able to continue assisting you.$B$BSome of the Deadwood furbolgs wear a distinctive headdress that may be used as a means of proof in thinning their numbers.  Bring me a feather from any headdresses you acquire; for every set of five you bring me, you will earn recognition amongst the Timbermaw.', 0), -- Feathers for Grazle
(27994, 0, 0, 0, 0, 'Ruumbo demands you defeat the jerks! I mean, the Deadwood tribe!', 32305), -- Ruumbo Demands Justice
(27997, 0, 0, 0, 0, 'Jadefire Glen is our first target in a series of coordinated efforts. The others will be dealt with in time.', 32305), -- The Corruption of the Jadefire
(27296, 1, 1, 0, 0, 'Have you put that torch to good use?', 32305), -- Raze Direhorn Post!
(27293, 1, 1, 0, 0, 'Were you able to find any trace of the orders?', 32305); -- The Grimtotem Plot

INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(27294, 1, 1, 0, 0, 'What did your search of Blackhoof Village reveal?', 32305), -- More than Coincidence
(27258, 3, 0, 0, 0, 'Hello there, $c. Something I can help you with?', 0), -- The Black Shield
(27415, 0, 0, 0, 0, 'You must hurry to the Dragonmurk, $n. With Onyxia\'s eggs riddled around the Wyrmbog, we face overwhelming numbers unless something is done quickly.$b$bDestroy her eggs! Don\'t let the black dragon plague spread across our homeland!', 32305), -- The Brood of Onyxia
(27348, 1, 1, 0, 0, '<Moxie looks frantic with worry.>$B$BDid the cargo survive? Did you find any of it?', 32305), -- Secure the Cargo!
(27347, 1, 1, 0, 0, 'Did you make any progress against those oozes?', 32305), -- Corrosion Prevention
(27340, 0, 1, 0, 0, 'Have you made any progress in stopping the Grimtotem attacks?', 32305), -- Direhorn Raiders
(27339, 1, 1, 0, 0, 'Did you get that venom? Morlann\'s going to discover that it\'s gone any moment now...', 32305), -- The Reagent Thief
(27336, 1, 1, 0, 0, 'Have you had any luck testing the totem?', 32305), -- The Grimtotem Weapon
(27229, 0, 0, 0, 0, 'Are you here about the sign?$B$BI don\'t want to talk about it unless you\'ve got proof of a kill.', 0), -- SMASH BROODQUEEN
(27244, 6, 0, 0, 0, 'You have something for me?', 0), -- The Lost Report
(27186, 6, 6, 0, 0, 'You have my blade??', 32305), -- Jarl Needs a Blade
(27191, 1, 1, 0, 0, 'Jarl\'s hungry. Just like that ogre.', 32305), -- Hungry as an Ogre!
(27190, 1, 1, 0, 0, 'Is it over?', 32305), -- Cleansing Witch Hill
(27189, 1, 1, 0, 0, 'Were you able to gather any of the herb? We must work quickly, before whatever evil is behind this infestation consolidates its hold on this area.', 32305), -- The Witch's Bane
(27184, 0, 0, 0, 0, 'Where are those eyes?', 32305), -- Jarl Needs Eyes
(27188, 0, 1, 0, 0, 'What have you learned from the spirits haunting this place?', 32305), -- What's Haunting Witch Hill?
(27183, 6, 6, 0, 0, 'Spice.  We could all use some spice in our life.  You agree?', 32305), -- Marsh Frog Legs
(25292, 1, 0, 0, 0, 'Hello, $c. You look to be caked in dust instead of mud. I take it you\'ve ventured here from the Barrens?', 0), -- Next of Kin
(27256, 0, 0, 0, 0, 'Did you get them sacs from the spiders?', 32305), -- The Black Shield
(25051, 0, 0, 0, 0, 'Have the eggs been destroyed?', 32305), -- Darkmist Extermination
(26682, 0, 0, 0, 0, 'I hope you prove more useful than the ogres around here.', 32305), -- A Shambling Threat
(27424, 0, 0, 0, 0, 'Me thirsty for grog. Me miss snuff too. Where is strongbox? You go get for Overlord Mok\'Morokk.$b$bGo find south in old home. Me too busy leading ogres to get.', 32305), -- Overlord Mok'Morokk's Concern
(28554, 0, 2, 0, 0, 'Aka\'Magosh, $c.', 32305), -- Warchief's Command: Dustwallow Marsh!
(27411, 1, 1, 0, 0, 'Brogg will have his revenge!', 32305), -- Challenge to the Black Flight
(27410, 1, 1, 0, 0, 'Brogg must know, have you brought peace to the violent spirits of the Stonemaul?', 32305), -- Spirits of Stonemaul Hold
(27409, 1, 1, 0, 0, 'Do you have the essences? Brogg must have them to avenge his friends!', 32305), -- The Essence of Enmity
(27408, 0, 0, 0, 0, 'You bring Stonemaul banner?', 32305), -- Banner of the Stonemaul
(28504, 0, 1, 0, 0, 'Oh good, you are here.', 32305), -- Warchief's Command: Thousand Needles!
(27412, 0, 1, 0, 0, 'You look pretty satisfied with yourself. Come to claim the bounty on that monstrous raptor?', 32305), -- WANTED: Goreclaw the Ravenous
(27413, 1, 1, 0, 0, 'Did you find any of the wyrmtail?', 32305), -- Catch a Dragon by the Tail
(26703, 0, 0, 0, 0, 'Firallon is still at large, $n.  The Bloodsail don\'t leave until he dies.', 32305), -- Bloodsail's End
(26697, 0, 0, 0, 0, 'We\'re still overwhelmed, matey.  Get back out there and protect my town!', 32305), -- The Final Voyage of the Brashtide
(26695, 0, 0, 0, 0, 'You\'re still alive?', 32305), -- Prepare for Takeoff
(26679, 0, 0, 0, 0, 'Guess who showed up while you were gone?', 0), -- Return to Revilgaz
(26664, 0, 0, 0, 0, 'You haven\'t much time before you have to return to Booty Bay!', 32305), -- Making Mutiny
(26663, 0, 0, 0, 0, 'The attack on Booty Bay draws nearer!', 32305), -- Sinking From Within
(26662, 0, 0, 0, 0, 'The details here are sparse.  You\'ll need to find some other members of the Brashtide Crew if you want information.', 32305), -- The Brashtide Crew
(26649, 0, 0, 0, 0, 'Those goblins will learn the fury of the Bloodsail!', 32305), -- Drive-By Piracy
(26647, 0, 0, 0, 0, 'You look a little green, $n.  You feelin\' alright?', 32305), -- Ol' Blasty
(26648, 0, 0, 0, 0, 'They\'re our mortal enemies, $n.  We have no choice but to fight them.', 32305), -- Our Mortal Enemies
(26633, 0, 0, 0, 0, 'Y\'try my patience, swabbie.  Yer this close t\'gettin\' kicked back OUT o\' the pirates.', 32305), -- Swabbing Duty
(26601, 0, 0, 0, 0, 'I\'ve been waiting for this moment, $n.', 32305), -- Mok'rash the Cleaver
(26602, 0, 0, 0, 0, 'Is it done, $r?', 32305), -- A Dish Best Served Huge
(26435, 0, 0, 0, 0, 'Yes, $r?  I\'m quite busy.', 0), -- I'm A Huge Liar and a Fraud
(26604, 0, 6, 0, 0, 'Please, $g my hero: sister;, dispose of the stalking panthers!', 32305), -- Protecting Her Royal Highness Poobah
(26535, 0, 0, 0, 0, 'Did he use shimmerweed?  I\'m guessing he used shimmerweed.$b$bNo wait... amberseeds!  It\'s gotta be amberseeds.', 32305), -- Recipe for Disaster
(26534, 0, 0, 0, 0, 'Come back when that pitcher\'s empty, $n.', 32305), -- Let's See What You've Got, Zanzil
(26533, 0, 0, 0, 0, 'Excellent... you\'re not a zombie yet.  That\'s good.$b$bOh, umm... nothing.  It\'s just that... that was a potential risk.  Did I forget to warn you?', 32305), -- Zanzil's Secret
(26494, 0, 0, 0, 0, 'Hey, is that the stuff?  From the magazine?', 0), -- Mixmaster Jasper
(26550, 0, 0, 0, 0, 'You have not done as I asked, $r.  Perhaps I was wrong to have selected you for this task...', 32305), -- Backdoor Dealings
(26495, 0, 0, 0, 0, 'Care to explain yourself, $c?', 0), -- Chabal
(26592, 0, 0, 0, 0, '<Flem\'s eyes sparkle.>$b$bAre those gems I see?', 32305), -- Diffractory Chromascope
(26434, 0, 0, 0, 0, 'Make sure the reagents are extra-cushy, $n.  A scratchy reagent simply won\'t do.', 32305), -- Primal Reagents of Power
(26493, 0, 0, 0, 0, 'I hope you used the extraction procedure we discussed.', 32305), -- There's Somebody Out There Who Wants It
(26487, 0, 0, 0, 0, 'Let\'s see... we\'re going to need some shotguns for our nature hikes, rowboats for the oil rig day trip, and...$b$bOh, you\'re back already?', 0), -- Akiris by the Bundle
(26433, 0, 0, 0, 0, '<Flem\'s ears perk up as you approach.>$b$bThe Holy Water of Clarity?  Is it here!?', 32305), -- The Holy Water of Clarity
(26489, 0, 0, 0, 0, 'Let\'s see... we\'re going to need some shotguns for our nature hikes, rowboats for the oil rig day trip, and...$b$bOh, hey Boss $n.  You\'re back already?', 0), -- It's You!!
(26450, 0, 0, 0, 0, 'Let\'s see \'em!', 32305), -- If They're Just Going to Leave Them Lying Around...
(14476, 0, 0, 0, 0, 'Did you get \'em? Did you get all three?', 32305), -- Rigged to Blow
(14464, 1, 0, 0, 0, 'I trust you\'ve got good news, $n?', 0), -- Lightning Strike Assassination
(24433, 0, 0, 0, 0, 'I trust you\'ve left our foes in complete disarray?', 32305), -- Let Them Feast on Fear
(14261, 0, 6, 0, 60, 'I wonder if there\'s any market for frozen, shattered drake parts. Maybe with a bit of marketing, I could pitch it as a new delicacy?', 32305), -- Ice Cold
(14297, 0, 1, 0, 0, 'There\'s no way I\'m paying them for time in captivity. Greedy little punks.', 32305), -- Pro-liberation
(24467, 0, 1, 0, 0, 'I will be glad to be done with these wretches.', 32305), -- Fade to Black
(14390, 0, 0, 0, 0, '<Azuregos glares at you.>', 32305), -- Easy is Boring
(24479, 0, 274, 0, 0, 'You\'re not very good at this. You\'re supposed to complete the trial BEFORE you come talk to me again. Make sense?', 32305), -- The Trial of Shadow
(24478, 0, 274, 0, 0, 'No. Just no. Do it right this time.', 32305), -- The Trial of Frost
(14300, 0, 274, 0, 0, 'Um, no. You\'re not done. Get back in there and get toasty!', 32305), -- The Trial of Fire
(14296, 0, 274, 0, 0, 'No no no, you\'ve got it all wrong. You were supposed to gather Energy from the Conduits before you came up here, remember?$B$BOne more time, with style!', 32305), -- Watch Your Step
(14435, 1, 1, 0, 0, 'If our ruse pays off, $n, we will forever drive a wedge between the Alliance and the Blackmaw.', 32305), -- The Blackmaw Doublecross
(14433, 6, 6, 0, 0, 'Do you have the robes? Andorel here has been whipping up some magic for us to use.', 32305), -- Diplomacy by Another Means
(14432, 0, 0, 0, 0, 'How goes the hunt? I sampled that briaroot stuff myself once, but it was too bitter, even for an old gravel-eater like myself.', 32305), -- A Pale Brew
(14226, 0, 0, 0, 0, 'Demons demons, always more demons. Like rabbits! But less cuddly... not so good for pulling out of hats either.', 32305), -- Trouble Under Foot
(14230, 0, 0, 0, 0, 'And here you are... back... talking to me again. I assume this means that you have my book?', 32305), -- Manual Labor
(14429, 0, 0, 0, 0, '<Andorel\'s image is blurry and indistinct. He squints at you and taps against the glass of the scrying stone.>$B$B$n, is that you? The resolution on this stone is terrible. What kind of hardware are they using?', 0), -- Arcane De-Construction
(14428, 0, 0, 0, 0, '<Andorel\'s distorted face appears within the scrying stone.>$B$B$n, have you made contact? What can you tell me?', 0), -- Amberwind's Journal
(14263, 0, 0, 0, 0, 'Do you have that thyme for me?', 32305), -- Waste of Thyme
(14249, 0, 0, 0, 0, 'My robe\'s looking pretty good. Did you bring those feathers?', 32305), -- Shear Will
(14250, 1, 1, 0, 0, 'I heard a few explosions. I can hardly tell if one of them was yours or not... these goblins can be quite a nuisance.', 32305), -- Renewable Resource
(14340, 0, 0, 0, 0, 'Hello.', 32305), -- Dressed to Impress
(14431, 1, 1, 0, 0, 'The Blackmaw are ferocious. Were they ever to organize, they would prove to be an immense disruption to our work here.', 32305), -- The Blackmaw Scar
(14324, 5, 0, 0, 0, 'You\'re back!', 0), -- Full of Hot Water
(14323, 0, 0, 0, 0, 'The Azshari Sea Sponge undulates with living water.', 32305), -- Absorbent
(14132, 0, 0, 0, 0, 'Nightmares of claws snapping. Nightmares!', 32305), -- That's Just Rude!
(14131, 0, 0, 0, 0, 'So tired, it\'s hard to concentrate.', 32305), -- A Little Pick-me-up
(24449, 5, 0, 0, 0, 'Ah, the $G man:woman; of the hour!', 0), -- Shore Leave
(14486, 1, 1, 0, 0, 'The blood elves eat those tablets up. Top dollar.', 32305), -- Handling the Goods
(14485, 0, 0, 0, 0, 'Ticker\'s a man after my own heart. Couldn\'t be prouder.', 32305), -- Ticker Required
(14484, 0, 0, 0, 0, 'You look to still be in one piece.', 32305), -- Head of the Snake
(14480, 0, 1, 0, 0, 'The Gob Squad is famous - nastiest fighters out of all the Wrenchmen. Somehow they manage not to blow themselves up much either, which increases life expectancy a bit.', 32305), -- Extermination
(14487, 1, 1, 0, 0, 'I love it when people leave priceless artifacts just lying around.', 32305), -- Still Beating Heart
(24436, 0, 0, 0, 0, 'It\'s a solid business model - Bedlam thought this one out pretty well.  We hire 3 times as many people as we intend to pay, and depend on the rest to lose their money to resurrection fees.$B$BSome of them even come back owing US money. Hah!', 32305), -- Halo Drops
(24435, 0, 1, 0, 0, 'After this, I think I may need to move away from the ocean. The smell of fish is almost too much to stand.', 32305), -- Mop Up
(24437, 0, 0, 0, 0, 'I should probably grab up some of that land along the cliff too.  Hmm...', 32305), -- First Come, First Served
(24458, 6, 0, 0, 0, 'What\'s that you\'ve got there - did Grapplehammer send you?', 0), -- A Hello to Arms
(14295, 0, 0, 0, 0, 'Is the job finished?', 32305), -- Sisters of the Sea
(14270, 0, 0, 0, 0, 'The Naga power stone pulses with an expectant hum.', 0), -- The Keystone Shard
(14388, 0, 0, 0, 0, 'Hey $n, you look shaken up. Did you scare the giant into going to the bathroom? Or yourself?', 32305), -- Azsharite Experiment Number Two
(14383, 0, 1, 0, 0, 'I trust you\'ve dug a significant number of tiny graves along the coast, yes?', 32305), -- The Terrible Tinkers of the Ruined Reaches
(14377, 0, 0, 0, 0, 'What did you discover? You look pale, $c!', 32305), -- Befriending Giants
(14262, 0, 0, 0, 0, 'I trust you left a trail of destruction in your wake?', 32305), -- To Gut a Fish
(14422, 0, 0, 0, 0, 'My beautiful children may attempt to bite you upon release, but at their stage of physical development, it is unlikely that their attacks will be fatal.', 32305), -- Raptor Raptor Rocket
(14322, 0, 0, 0, 0, 'Are they dead? Is it safe to go outside again?', 32305), -- Bad Science! Bad!
(14216, 6, 6, 0, 0, 'Did you discover anything at the lake? You\'re soaking wet.', 32305), -- Mystery of the Sarcen Stone
(14423, 0, 0, 0, 0, 'How is Margene doin\'? Running like her sweet self again?', 32305), -- Dozercism
(14215, 0, 0, 0, 0, 'You shudder, the memories of another life threatening to overpower you...', 32305), -- Memories of the Dead
(14209, 273, 273, 0, 0, 'Margene is one heck of a machine, isn\'t she?', 32305), -- Gunk in the Trunk
(14202, 0, 0, 0, 0, 'No buncha dead elves can put a stop to progress. Not on my watch!', 32305), -- Survey the Lakeshore
(14201, 0, 0, 0, 0, 'Have you gotten your hands dirty for me?', 32305), -- A Thousand Stories in the Sand
(24452, 0, 6, 0, 20, 'Our stealth field generator has the same acronym as our rocket launcher. Probably poor planning on our part.', 32305), -- Profitability Scouting
(14472, 0, 1, 0, 0, 'Sweet little piece of goblin technology, that thing is.', 32305), -- In The Face!
(14471, 0, 0, 0, 0, 'KABOOM!', 32305), -- First Degree Mortar
(14470, 6, 6, 0, 0, 'Where\'s my rocket launcher, recruit?', 32305), -- Military Breakthrough
(14469, 1, 1, 0, 0, 'Nothing wrong with recycled goods.', 32305), -- Hand-me-downs
(14194, 0, 0, 0, 0, 'Hey look, all your limbs are intact.', 0), -- Refleshification
(14192, 0, 0, 0, 0, '<The weapons cabinet is loaded with heinous and broken experimental devices, some of which still have goblin limbs attached. You discover the laser drill lovingly ensconced in a velvet-lined wooden case.>', 0), -- Prismbreak
(14190, 0, 0, 0, 0, '<Strange goblin speakers hiss and crackle.>', 0), -- The Perfect Prism
(14165, 0, 5, 0, 0, 'Get to the strip mine, $n, and get me a sample of one of my former workers!', 32305), -- Stone Cold
(14161, 0, 6, 0, 0, 'Are those beasts good and dead?', 32305), -- Basilisk Bashin'
(14117, 0, 0, 0, 0, 'Are the hills no longer alive, $c?', 32305); -- The Eyes of Ashenvale

UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=28701; -- Out of Harm's Way
UPDATE `quest_request_items` SET `CompletionText`='What are you doing, $n? We need that essence.', `VerifiedBuild`=32305 WHERE `ID`=28839; -- Magic Prehistoric
UPDATE `quest_request_items` SET `EmoteOnComplete`=11, `EmoteOnIncomplete`=11, `VerifiedBuild`=32305 WHERE `ID`=28722; -- Yetiphobia
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=28625; -- Chop Chop
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=28472; -- Words of the High Chief
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Now, what\'s this, $n?' WHERE `ID`=28471; -- The Final Piece
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='I hope you found something, $n. The Winterfall are becoming increasingly aggressive!' WHERE `ID`=28467; -- Mystery Goo
UPDATE `quest_request_items` SET `EmoteOnComplete`=11, `EmoteOnIncomplete`=11, `VerifiedBuild`=32305 WHERE `ID`=28540; -- Doin' De E'ko Magic
UPDATE `quest_request_items` SET `CompletionText`='We very much appreciate what you have done for the Timbermaw, $n.  Your continued efforts will surely earn my tribe\'s trust and respect.', `VerifiedBuild`=32305 WHERE `ID`=28522; -- Winterfall Activity
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=13906; -- They Grow Up So Fast
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=13887; -- Venomhide Eggs
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=274, `VerifiedBuild`=32305 WHERE `ID`=13850; -- Toxic Tolerance
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='Do you have some venom from a Vicious Night Web Spider yet, $n?  It\'s the final component I need in order to test my experiment.', `VerifiedBuild`=32305 WHERE `ID`=25013; -- A Little Oomph
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=25009; -- At War With The Scarlet Crusade
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=25056; -- Grisly Grizzlies
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='Do you have five duskbat pelts yet, $n?', `VerifiedBuild`=32305 WHERE `ID`=24988; -- The Chill of Death
UPDATE `quest_request_items` SET `CompletionText`='Our battles with the Scourge wage on, $n.  Do your part and throw those cursed, mindless undead back into the Plaguelands!', `VerifiedBuild`=32305 WHERE `ID`=25004; -- The Mills Overrun
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='$n, were you able to obtain those scales from the murlocs?', `VerifiedBuild`=32305 WHERE `ID`=24995; -- Off the Scales
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=24998; -- Maggot Eye
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=24994; -- Doom Weed
UPDATE `quest_request_items` SET `EmoteOnComplete`=14 WHERE `ID`=24996; -- Holland's Experiment
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `CompletionText`='Have you collected the darkhound blood yet, $n? Time is fleeting!', `VerifiedBuild`=32305 WHERE `ID`=24990; -- Darkhound Pounding
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=25038; -- Gordo's Task
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=24981; -- A Thorn in our Side
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=24977; -- Johaan's Experiment
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=24980; -- The Scarlet Palisade
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='Were you able to gather 10 pumpkins yet, $n?', `VerifiedBuild`=32305 WHERE `ID`=24975; -- Fields of Grief
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=25757; -- Get Koalbeard!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=25672; -- Carcass Collection
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=25661; -- With a Little Help...
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=25628; -- Two-Tusk Takedown
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=25610; -- Sunken Treasure
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=25516; -- Down in the Deeps
UPDATE `quest_request_items` SET `EmoteOnComplete`=397 WHERE `ID`=25505; -- Do Me a Favor?
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=24667; -- Firestone Point
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `CompletionText`='Give me the plans, quickly! Our time grows short.$B$BMostly because I\'ve been eating my disguise.', `VerifiedBuild`=32305 WHERE `ID`=24685; -- Dwarf Fortress
UPDATE `quest_request_items` SET `EmoteOnComplete`=15, `EmoteOnIncomplete`=15, `VerifiedBuild`=32305 WHERE `ID`=24621; -- Smarts-is-Smarts
UPDATE `quest_request_items` SET `CompletionText`='You\'ve gotta have heart, $n. All you really need is heart.', `VerifiedBuild`=32305 WHERE `ID`=24620; -- Hearts-is-Hearts
UPDATE `quest_request_items` SET `EmoteOnComplete`=274, `EmoteOnIncomplete`=274, `CompletionText`='Watch your back, $c. They could be anywhere.$B$B<Bloodhilt peers around the fortress with narrowed eyes.>', `VerifiedBuild`=32305 WHERE `ID`=24634; -- Intelligence Warfare
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=24631; -- Flightmare
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='The Alliance is nothing. Swarms of those critter-crawlys?$B$B<Crawgol shudders.>', `VerifiedBuild`=32305 WHERE `ID`=24654; -- Silithissues
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=24573; -- Honoring the Dead
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=24569; -- Siegebreaker
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=24542; -- A Curious Bloom
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=27342; -- In Time, All Will Be Revealed
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32305 WHERE `ID`=27226; -- Hair of the Dog
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=27096; -- Orcs are in Order
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32305 WHERE `ID`=27082; -- Playing Dirty
UPDATE `quest_request_items` SET `EmoteOnComplete`=25, `CompletionText`='Kneel before your queen, $n.' WHERE `ID`=27056; -- Belmont's Report
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=26998; -- Iterating Upon Success
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=26995; -- Guts and Gore
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=26992; -- Agony Abounds
UPDATE `quest_request_items` SET `CompletionText`='Find any more encrypted texts?  Bring me a good batch of them, this decoding work takes some time.' WHERE `ID`=8324; -- Still Believing
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='What is this you bring to me, $n?' WHERE `ID`=8287; -- A Terrible Purpose
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=32305 WHERE `ID`=8323; -- True Believers
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=8285; -- The Deserter
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Oh my! What do you have there, $n?' WHERE `ID`=8314; -- Unraveling the Mystery
UPDATE `quest_request_items` SET `EmoteOnComplete`=25, `EmoteOnIncomplete`=25, `VerifiedBuild`=32305 WHERE `ID`=8310; -- Breaking the Code
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=8309; -- Glyph Chasing
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Waste no time, $n!', `VerifiedBuild`=32305 WHERE `ID`=8304; -- Dearest Natalia
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=32305 WHERE `ID`=8284; -- The Twilight Mystery
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=32305 WHERE `ID`=8278; -- Noggle's Last Hope
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=32305 WHERE `ID`=8281; -- Stepping Up Security
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=8319; -- Encrypted Twilight Texts
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `CompletionText`='$n, have you yet defeated Vyral the Vile?  Do you have his signet ring?', `VerifiedBuild`=32305 WHERE `ID`=8321; -- Vyral the Vile
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=32305 WHERE `ID`=8283; -- Wanted - Deathclasp, Terror of the Sands
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=8318; -- Secret Communication
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=5, `CompletionText`='Enter the desert and find the Twilight geolords, $n.  Return to me after they are slain.', `VerifiedBuild`=32305 WHERE `ID`=8320; -- Twilight Geolords
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=32305 WHERE `ID`=8277; -- Deadly Desert Venom
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=32305 WHERE `ID`=8280; -- Securing the Supply Lines
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=208; -- Big Game Hunter
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=193; -- Panther Mastery
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=197; -- Raptor Mastery
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=32305 WHERE `ID`=185; -- Tiger Hunting
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=26269; -- The Green Hills of Stranglethorn
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=32305 WHERE `ID`=190; -- Panther Hunting
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `CompletionText`='I never met a hunter who got any kills by standing around the campfire - well, except for my father.  Were you planning on killing those Stranglethorn Raptors or were you hoping they would die of old age?', `VerifiedBuild`=32305 WHERE `ID`=194; -- Raptor Hunting
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='What news of Naias, $n?', `VerifiedBuild`=32305 WHERE `ID`=9457; -- An Unusual Patron
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `CompletionText`='Do not fail me, $n. If we can bend this Bloodscalp magic to our will, my people may yet eliminate the Amani threat.', `VerifiedBuild`=32305 WHERE `ID`=9436; -- Bloodscalp Insight
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `CompletionText`='Wake up! Wake up, $n! This is not a dream. You really are entrenched in the midst of a raging battle!' WHERE `ID`=7161; -- Proving Grounds
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='I\'m practically naked here, $n. Help me out, eh?', `VerifiedBuild`=32305 WHERE `ID`=28487; -- Humbert's Personal Problems
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32305 WHERE `ID`=28485; -- Yetimus the Yeti Lord
UPDATE `quest_request_items` SET `EmoteOnComplete`=25, `EmoteOnIncomplete`=25, `CompletionText`='Bring me yeti hearts, $n.', `VerifiedBuild`=32305 WHERE `ID`=28484; -- The Heart of the Matter
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32305 WHERE `ID`=28489; -- Stagwiches
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32305 WHERE `ID`=28325; -- Green Living
UPDATE `quest_request_items` SET `EmoteOnComplete`=274, `CompletionText`='Do not waste my time, $n.' WHERE `ID`=28237; -- A Blight Upon the Land
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32305 WHERE `ID`=28231; -- Do it for Twinkles
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32305 WHERE `ID`=28209; -- Freedom for Lydon
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32305 WHERE `ID`=28199; -- For Science!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=28196; -- The Battle for Hillsbrad
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=28114; -- Glorious Harvest
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `CompletionText`='Recover our \"supplies,\" $n!', `VerifiedBuild`=32305 WHERE `ID`=28144; -- Thieving Little Monsters!
UPDATE `quest_request_items` SET `CompletionText`='Yes $c, what can I assist you with?  You walk among us peacefully, though there is assuredly something amiss.  I sense something... something troubling...' WHERE `ID`=8470; -- Deadwood Ritual Totem
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=28359; -- The Core of Kroshius
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=28119; -- Purity From Corruption
UPDATE `quest_request_items` SET `CompletionText`='Have you found the crying violet yet, $n? We need them quickly.', `VerifiedBuild`=32305 WHERE `ID`=28116; -- Crying Violet
UPDATE `quest_request_items` SET `CompletionText`='Did you find the documents, $n?  They hold information vital to the stability of the Alliance and, hence, vital to the security of the Horde.', `VerifiedBuild`=32305 WHERE `ID`=1202; -- The Theramore Docks
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=32305 WHERE `ID`=1168; -- Army of the Black Dragon
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=27254; -- The Black Shield
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=27260; -- Lieutenant Paval Reethe
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Did you find the infiltrators, $n?', `VerifiedBuild`=32305 WHERE `ID`=1201; -- Theramore Spies
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32305 WHERE `ID`=27407; -- Bloodfen Feathers
UPDATE `quest_request_items` SET `EmoteOnComplete`=3, `EmoteOnIncomplete`=3, `VerifiedBuild`=32305 WHERE `ID`=26614; -- Keep An Eye Out
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=26613; -- Up to Snuff
UPDATE `quest_request_items` SET `CompletionText`='$n, did you find those debtors?', `VerifiedBuild`=32305 WHERE `ID`=26595; -- Kill-Collect
UPDATE `quest_request_items` SET `CompletionText`='Here here, $n.  Did you get Shaky\'s payment?' WHERE `ID`=26594; -- Return to MacKinley
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=26612; -- Details of the Attack
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID`=26593; -- Scaring Shaky
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=26598; -- The Heart of Mokk
UPDATE `quest_request_items` SET `CompletionText`='Ahoy, $n!  Did you find Gorlash?  That chest was my favorite, and it has a hidden compartment that held my greatest treasures!', `VerifiedBuild`=32305 WHERE `ID`=26599; -- The Captain's Chest
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=26606; -- Mukla's Demise
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=26605; -- Grubby Little Paws
UPDATE `quest_request_items` SET `EmoteOnComplete`=274, `EmoteOnIncomplete`=274, `VerifiedBuild`=32305 WHERE `ID`=14371; -- A Gigantic Snack
UPDATE `quest_request_items` SET `CompletionText`='I suspect the archives are close, $n. Locate those plans!', `VerifiedBuild`=32305 WHERE `ID`=14408; -- Nine's Plan
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=14128; -- Return of the Highborne?
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32305 WHERE `ID`=14197; -- A Quota to Meet
UPDATE `quest_request_items` SET `CompletionText`='<Labor Captain Grabbit\'s voice crackles over the radio.>$B$BHey $n! Are you reading this?$B$BPiloting that sucker is easy. Push the pedals for your pedal controls and, ah, move the levers for your lever controls. Got it?', `VerifiedBuild`=32305 WHERE `ID`=14129; -- Runaway Shredder!

UPDATE `quest_request_items` SET `VerifiedBuild`=32305 WHERE `ID` IN (28828, 28840, 28838, 28837, 28631, 28629, 28632, 28610, 28537, 28518, 28530, 28469, 25029, 24997, 25090, 24976, 24974, 24953, 24931, 24933, 25026, 25025, 25522, 25021, 25521, 24653, 24824, 24619, 24551, 24574, 24571, 24570, 24534, 27345, 27193, 27180, 8279, 8282, 26345, 26344, 26343, 28342, 28341, 28208, 28207, 28044, 28049, 27989, 28148, 27414, 9437, 26634, 26635, 26630, 26629, 26600, 26597, 14370, 14308, 14258, 14118);

DELETE FROM `quest_request_items` WHERE `ID` IN (27480 /*Ley Energies*/, 27085 /*Supporting the Troops*/, 27086 /*Ashes to Ashes*/, 27084 /*The Farmers' Militia*/, 26937 /*When Death is Not Enough*/, 26930 /*After the Crusade*/, 27117 /*Brute Strength*/, 26924 /*Scholomancer*/, 26923 /*War Machines*/, 26921 /*Scourge First... Alliance Later*/, 26922 /*The Endless Flow*/, 27055 /*Students of Krastinov*/, 26955 /*Zen'Kiki and the Cultists*/, 27151 /*Taelan Fordring's Legacy*/, 27157 /*Drudges... <Sigh>*/, 27156 /*It's About Time!*/, 27001 /*This Means WAR (Wild Arachnid Roundup)*/, 27013 /*Too Close for Comfort*/, 27000 /*Learning the Ropes*/, 26954 /*A Different Approach*/, 26956 /*I Ain't Sayin' You a Gourd-Digger...*/, 26953 /*Zen'Kiki, the Druid*/, 26978 /*Who Needs Cauldrons?*/, 26933 /*Foes Before Hoes*/, 26387 /*Starvation Diet*/, 26367 /*Ongo'longo's Revenge*/, 26308 /*It's Ours Now*/, 26307 /*Death to the Vilebranch*/, 26357 /*Faces of Evil*/, 26306 /*Start Taking Back*/, 26267 /*Skulk Rock Clean-Up*/, 26224 /*Hunt the Savages*/, 26223 /*Stalking the Stalkers*/, 26240 /*Stomp To My Beat*/, 26238 /*The Savage Dwarves*/, 26263 /*Thornar Thunderclash*/, 14065 /*Sharing a Bountiful Feast*/, 26211 /*Snapjaws, Mon!*/, 26912 /*The Princess Unleashed*/, 26108 /*Guile of the Raptor*/, 26429 /*Crush the Witherbark*/, 26055 /*Drowned Sorrows*/, 26033 /*Trol'kalar*/, 26032 /*Sigil of Arathor*/, 26029 /*The Real Threat*/, 26031 /*Sigil of Thoradin*/, 26030 /*Sigil of Strom*/, 26025 /*The Traitor Orc*/, 26027 /*Call to Arms*/, 26053 /*Clearing the Highlands*/, 26428 /*To Steal From Thieves*/, 27391 /*Hidden Treasures*/, 27421 /*Amidst Death, Life*/, 27420 /*Postponing the Inevitable*/, 27448 /*The Trek Continues*/, 27382 /*Rough Roads*/, 27381 /*Traveling Companions*/, 27373 /*Onward, to Light's Hope Chapel*/, 27371 /*What I Do Best*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(27480, 6, 0, 0, 0, 'What\'s that you\'ve got there, $n?', 0), -- Ley Energies
(27085, 0, 0, 0, 0, 'Dark Lady watch over you.', 32638), -- Supporting the Troops
(27086, 0, 0, 0, 0, 'You will find them to the west, $n.  Do not fail me.', 32638), -- Ashes to Ashes
(27084, 0, 0, 0, 0, 'Deal with these farmers now, $c.  That is your primary objective.  Teach them how truly unprepared they were for the horrors of war.', 32638), -- The Farmers' Militia
(26937, 0, 0, 0, 0, 'Have you lost your way, $n?', 32638), -- When Death is Not Enough
(26930, 0, 0, 0, 0, 'Have you seen the camp yet, $n?', 32638), -- After the Crusade
(27117, 0, 0, 0, 0, 'I will not rest until the Lich King\'s taint is lifted from Andorhal.', 32638), -- Brute Strength
(26924, 0, 0, 0, 0, 'I will not rest until the Lich King\'s taint is lifted from Andorhal.', 32638), -- Scholomancer
(26923, 0, 0, 0, 0, 'How long must I wait before you\'ve done my bidding, $r?', 32638), -- War Machines
(26921, 0, 0, 0, 0, 'Thin out the Scourge forces, $n.  Our victory depends on keeping their numbers down.', 32638), -- Scourge First... Alliance Later
(26922, 0, 0, 0, 0, 'I know what those devices sound like when they\'ve blown up... and I haven\'t heard that sound yet.  Get back out there, $n.', 32638), -- The Endless Flow
(27055, 0, 0, 0, 0, 'How is your investigation proceeding, $n?', 32638), -- Students of Krastinov
(26955, 0, 0, 0, 0, 'By the grace of the Earthmother, I hope this works.', 32638), -- Zen'Kiki and the Cultists
(27151, 0, 0, 0, 0, 'Welcome back.', 32638), -- Taelan Fordring's Legacy
(27157, 0, 0, 0, 0, 'I need to get those drudges back to work.', 32638), -- Drudges... <Sigh>
(27156, 0, 0, 0, 0, 'I\'m not paying you to talk to me.  I\'m paying you to talk with my soldiers... and then fight with them.', 32638), -- It's About Time!
(27001, 0, 1, 0, 0, 'I don\'t need you to kill the spiders... that\'s what these soldiers are for.  Think of it as killing two birds with one stone: we\'re getting rid of the spiders, and the recruits are getting valuable combat experience.', 32638), -- This Means WAR (Wild Arachnid Roundup)
(27013, 0, 0, 0, 0, 'I have a family to raise, and I need to do whatever I can to protect them.', 32638), -- Too Close for Comfort
(27000, 0, 1, 0, 0, 'The spiders tend to be a little skittish.  One of the mustangs should be enough to scare them away.', 32638), -- Learning the Ropes
(26954, 0, 0, 0, 0, 'Back so soon?', 32638), -- A Different Approach
(26956, 0, 0, 0, 0, 'Have you finished killing... er, removing those plants yet?', 32638), -- I Ain't Sayin' You a Gourd-Digger...
(26953, 0, 0, 0, 0, 'Zen\'Kiki needs a... a big $g brother: sister;, like you, to help him gain some confidence.', 32638), -- Zen'Kiki, the Druid
(26978, 0, 1, 0, 0, 'I see you\'re still carrying some of those drums with you, $n.  Don\'t return until they\'ve all been placed.', 32638), -- Who Needs Cauldrons?
(26933, 0, 0, 0, 0, 'For a bunch of combat-trained goons, they certainly have made some progress on that farm.', 32638), -- Foes Before Hoes
(26387, 0, 0, 0, 0, 'Don\'t get squeamish on me. I\'d be over there ripping open cocoons myself if I didn\'t have to keep all this equipment running.', 32638), -- Starvation Diet
(26367, 0, 0, 0, 0, 'Ongo\'longo still lies in chains.', 32638), -- Ongo'longo's Revenge
(26308, 0, 0, 0, 0, 'You\'ll be quite busy if you want to spill as much blood as they have.', 32638), -- It's Ours Now
(26307, 0, 0, 0, 0, 'What are you waiting for?', 32638), -- Death to the Vilebranch
(26357, 0, 0, 0, 0, 'I don\'t see enough lights burnin\', $c. Better get goin\'.', 32638), -- Faces of Evil
(26306, 0, 0, 0, 0, 'You\'d better not get cold feet on me.', 32638), -- Start Taking Back
(26267, 0, 1, 0, 0, 'Don\'t get caught offguard. Even if one slime doesn\'t seem like much, once one gets you pinned down... the others won\'t be far behind.', 32638), -- Skulk Rock Clean-Up
(26224, 0, 5, 0, 0, 'Clear your head of impure thoughts, $r. Become one with the wilds!', 32638), -- Hunt the Savages
(26223, 0, 5, 0, 0, 'Show them the might of Revantusk!', 32638), -- Stalking the Stalkers
(26240, 0, 0, 0, 0, 'Back so soon? Don\'t be shy, now.', 32638), -- Stomp To My Beat
(26238, 0, 0, 0, 0, 'Don\'t be loitering\' around the village all day now. If you\'re staying with us, I expect you to fight for us.', 32638), -- The Savage Dwarves
(26263, 0, 0, 0, 0, 'I\'m not as old as I look, $r... I can still hear that dwarf from here.', 32638), -- Thornar Thunderclash
(14065, 0, 6, 0, 0, 'Did you eat enough at a Bountiful Table?', 32638), -- Sharing a Bountiful Feast
(26211, 0, 6, 0, 0, 'How goes the hunt?', 32638), -- Snapjaws, Mon!
(26912, 0, 0, 0, 0, 'The Shards of Myzrael are now strangely quiet.', 32638), -- The Princess Unleashed
(26108, 0, 0, 0, 0, 'My preparations are made, all I need are the raptor hearts.', 32638), -- Guile of the Raptor
(26429, 0, 1, 0, 0, 'Haven\'t completed my task yet? Are you scared, coward?', 32638), -- Crush the Witherbark
(26055, 0, 19, 0, 0, 'Bah, maybe I should go kill those naga scum myself.  It\'s obvious you\'re not goin\' to do it.$b$bMaybe I can find some knitting needles so you can keep yourself busy.', 32638), -- Drowned Sorrows
(26033, 1, 1, 0, 0, 'Have you Trol\'kalar?', 32638), -- Trol'kalar
(26032, 0, 0, 0, 0, 'Have you the sigil?', 32638), -- Sigil of Arathor
(26029, 0, 0, 0, 0, 'Speak quickly.', 32638), -- The Real Threat
(26031, 1, 1, 0, 0, 'All five pieces are needed to restore the sigil...', 32638), -- Sigil of Thoradin
(26030, 0, 0, 0, 0, 'Only the Syndicate agents in Stromgarde will have the sigil. Spilling blood outside the fortress\'s walls will be a waste of your time.', 32638), -- Sigil of Strom
(26025, 0, 0, 0, 0, 'The burning in my blood... it grows by the day. The warlock must be stopped.', 32638), -- The Traitor Orc
(26027, 0, 1, 0, 0, 'The ogres lurk in the corner of the ruins, away from the humans. Don\'t forget I\'m only rewarding you for slaughtering ogres this time, $c. You can do what you want for fun, but don\'t expect extra credit.', 32638), -- Call to Arms
(26053, 0, 1, 0, 0, 'You\'ll learn not to bother a Deathstalker unless you have news of success in time. Until then, try to keep your mouth shut in general.', 32638), -- Clearing the Highlands
(26428, 5, 5, 0, 0, 'Kill them all and bring me their heads!', 32638), -- To Steal From Thieves
(27391, 0, 0, 0, 0, 'This chest is old and covered in grime.', 0), -- Hidden Treasures
(27421, 0, 0, 0, 0, 'I am confident that nature will find a foothold within those ziggurats.', 32638), -- Amidst Death, Life
(27420, 0, 0, 0, 0, 'If the Cenarion Circle is ever going to return the Fungal Vale to its original, healthy state, those plague disseminators must be the first things to go.', 32638), -- Postponing the Inevitable
(27448, 0, 0, 0, 0, 'Once we get to Light\'s Shield Tower, the boys can head over to Light\'s Hope Chapel.  It\'s close enough that they can walk.', 32638), -- The Trek Continues
(27382, 0, 0, 0, 0, 'The road I walk is lonely, but I do so for duty.', 32638), -- Rough Roads
(27381, 0, 0, 0, 0, 'Any luck?', 32638), -- Traveling Companions
(27373, 0, 0, 0, 0, '', 32638), -- Onward, to Light's Hope Chapel
(27371, 0, 0, 0, 0, 'I can\'t wait to lay waste to these undead.  Boom!', 32638); -- What I Do Best

UPDATE `quest_request_items` SET `CompletionText`='I wouldn\'t expect you to indulge the whims of a nostalgic old man, $n.  Still, if you find yourself in the area...', `VerifiedBuild`=32638 WHERE `ID`=27017; -- Memories from a Lost Past
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32638 WHERE `ID`=26381; -- The Eye of Shadra
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32638 WHERE `ID`=26309; -- Dark Vessels
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32638 WHERE `ID`=26283; -- Prime Slime
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32638 WHERE `ID`=26268; -- Skulk Rock Supplies
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `CompletionText`='<Lard rubs his enormous belly.>$B$BLard so hungry.', `VerifiedBuild`=32638 WHERE `ID`=26212; -- Lard Lost His Lunch
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32638 WHERE `ID`=26210; -- Gammerita, Mon!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26052; -- Speak to Shakes
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32638 WHERE `ID`=26051; -- Sunken Treasure
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32638 WHERE `ID`=27389; -- Marauders of Darrowshire
UPDATE `quest_request_items` SET `CompletionText`='Do you have the relics, $n?', `VerifiedBuild`=32638 WHERE `ID`=27388; -- Heroes of Darrowshire
UPDATE `quest_request_items` SET `CompletionText`='Did you find the skull and the sword, $n?', `VerifiedBuild`=32638 WHERE `ID`=27387; -- Villains of Darrowshire
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=27386; -- A Strange Historian
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `CompletionText`='Did you find the hideout, $n?  Did you take care of Zaeldarr?', `VerifiedBuild`=32638 WHERE `ID`=27432; -- Zaeldarr the Outcast

UPDATE `quest_request_items` SET `VerifiedBuild`=32638 WHERE `ID` IN (26925, 27054, 27012, 27011, 26999, 26418, 26406, 26382, 26369, 26363, 26368, 26310, 26366, 26225, 26042, 26107, 26022, 27392, 27384, 27368);

DELETE FROM `quest_request_items` WHERE `ID` IN (27533 /*A Fate Worse Than Butchery*/, 27532 /*The Plaguewood Tower*/, 27530 /*The Corpsebeasts*/, 27529 /*Defenders of Darrowshire*/, 27528 /*Scourged Mass*/, 27525 /*Guardians of Stratholme*/, 27521 /*Wretched Hive of Scum and Villainy*/, 27481 /*Out of the Ziggurat*/, 27477 /*The Corpulent One*/, 27613 /*The Assassin*/, 27612 /*Victory From Within*/, 27619 /*The Commander*/, 27616 /*The Huntsman*/, 27615 /*The Wrathcaster*/, 28756 /*Aberrations of Bone*/, 27467 /*Buried Blades*/, 27465 /*Argent Call: The Noxious Glade*/, 27464 /*Argent Call: The Trial of the Crypt*/, 27453 /*Catalysm*/, 27450 /*Frederick's Fish Fancy*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(27533, 0, 18, 0, 0, 'I cry for the poor pigs.', 32722), -- A Fate Worse Than Butchery
(27532, 0, 0, 0, 0, 'Highbeacon\'s Parcel... is Argus safe?  Did something happen?', 0), -- The Plaguewood Tower
(27530, 0, 0, 0, 0, 'This is my final task for you.  I wish you luck.', 32722), -- The Corpsebeasts
(27529, 0, 5, 0, 0, 'The poor defenders of Darrowshire cry out for freedom.', 32722), -- Defenders of Darrowshire
(27528, 0, 0, 0, 0, 'Hold tightly onto your rage, $r.  Let it guide your strikes against these beasts.', 32722), -- Scourged Mass
(27525, 0, 0, 0, 0, 'We\'re getting close.  I only hope it\'s not too late.', 32722), -- Guardians of Stratholme
(27521, 0, 0, 0, 0, 'You have no idea how difficult it was for me to pull myself away, $r.  I nearly ended up one of them.', 32722), -- Wretched Hive of Scum and Villainy
(27481, 0, 0, 0, 0, 'I have waited long for this day.', 32722), -- Out of the Ziggurat
(27477, 0, 6, 0, 0, 'Have I told you lately that I hate you?', 32722), -- The Corpulent One
(27613, 0, 0, 0, 0, 'Fight well, $n.', 32722), -- The Assassin
(27612, 0, 0, 0, 0, 'One hundred soldiers is few enough.  Setbacks like this only decrease our chances of success.', 32722), -- Victory From Within
(27619, 0, 0, 0, 0, 'If you get a chance before you put her down, tell her I sent my regards.', 32722), -- The Commander
(27616, 0, 0, 0, 0, 'If it were up to me, I\'d throw him off the edge of the tower.', 32722), -- The Huntsman
(27615, 0, 0, 0, 0, 'If you don\'t do it, I might go kill him myself, $n.', 32722), -- The Wrathcaster
(28756, 0, 1, 0, 0, 'Have you carried on our fight against the remnants of the Scourge in these lands?', 32722), -- Aberrations of Bone
(27467, 0, 0, 0, 0, 'Are you still here?', 32722), -- Buried Blades
(27465, 0, 0, 0, 0, 'The three of you still have a job to do.', 32722), -- Argent Call: The Noxious Glade
(27464, 0, 0, 0, 0, 'Your test is not yet complete.', 32722), -- Argent Call: The Trial of the Crypt
(27453, 0, 0, 0, 0, 'We\'re nearly ready to strike, $n.', 0), -- Catalysm
(27450, 0, 0, 0, 0, 'Did... did you bring the fish?', 32722); -- Frederick's Fish Fancy

UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32722 WHERE `ID`=27523; -- Duskwing, Oh How I Hate Thee...
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `CompletionText`='We have no time, $n!  We must press on!', `VerifiedBuild`=32722 WHERE `ID`=27489; -- Nobody to Blame but Myself
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=28755; -- Annals of the Silver Hand
UPDATE `quest_request_items` SET `CompletionText`='Everything going alright so far, $n?', `VerifiedBuild`=32722 WHERE `ID`=27452; -- Dark Garb
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32722 WHERE `ID`=27451; -- To Kill With Purpose

UPDATE `quest_request_items` SET `VerifiedBuild`=32722 WHERE `ID` IN (27534, 27531, 27539, 27488, 27479, 27614, 27456, 27458);

DELETE FROM `quest_request_items` WHERE `ID` IN (12948 /*The Champion of Anguish*/, 12936 /*The Amphitheater of Anguish: Korrak the Bloodrager!*/, 12935 /*The Amphitheater of Anguish: Tuskarrmageddon!*/, 12934 /*The Amphitheater of Anguish: From Beyond!*/, 12933 /*The Amphitheater of Anguish: Magnataur!*/, 12932 /*The Amphitheater of Anguish: Yggdras!*/, 12903 /*That's What Friends Are For...*/, 27916 /*Ruag's Report*/, 27910 /*Last Regrets*/, 27909 /*The Purespring*/, 27908 /*Secrets of the Mire*/, 27907 /*Prayerblossom*/, 27857 /*We're Under Attack!*/, 27856 /*Marking the Fallen*/, 27855 /*Reinforcements Denied*/, 27854 /*Tides of Darkness*/, 27853 /*Lumbering Oafs*/, 27852 /*Orcs and Humans*/, 27704 /*Legends of the Sunken Temple*/, 27694 /*Pool of Tears*/, 27818 /*Slithering Signs*/, 27757 /*The Darkest Depths*/, 27691 /*Marshfin Madness*/, 27598 /*Kill Gil*/, 27656 /*Croc-Out*/, 28029 /*Set Them Ablaze!*/, 28028 /*Siege!*/, 27984 /*Lunthistle's Tale*/, 27976 /*Curse These Fat Fingers*/, 27980 /*The Spiders Have to Go*/, 27960 /*The Fewer, the Better*/, 12304 /*Beachfront Property*/, 12449 /*Return to the Earth*/, 12448 /*Heated Battle*/, 12144 /*Pest Control*/, 12111 /*Where the Wild Things Roam*/, 12036 /*From the Depths of Azjol-Nerub*/, 28455 /*Glory Amidst Chaos*/, 28451 /*A Delivery for Neeralak*/, 28450 /*A Delivery for Thorg'izog*/, 28452 /*A Delivery for Xi'lun*/, 28448 /*A Deal With a Dragon*/, 28447 /*Draconic Vanguard*/, 28446 /*Blood Tour*/, 28445 /*A Heap of Delicious Worg*/, 28444 /*Latent Demons of the Land*/, 28443 /*Blackened Ashes*/, 28491 /*Not Fireflies, Flameflies*/, 28439 /*I Am the Law and I Am the Lash*/, 28438 /*Trial by Magma*/, 28433 /*Grunt Work*/, 28227 /*Golem Training*/, 28225 /*Prove Yer Allegiance*/, 28424 /*Shadow Boxing*/, 28418 /*Burning Vengeance*/, 11677 /*Stop the Plague*/, 11675 /*A Proper Death*/, 11627 /*Boiling Point*/, 11719 /*A Suitable Test Subject*/, 11611 /*Taken by the Scourge*/, 25720 /*The Downfall of Marl Wormthorn*/, 25719 /*Demoniac Vessel*/, 25717 /*The Demons and the Druid*/, 25706 /*Neptool's Revenge*/, 25703 /*Atrocities*/, 25695 /*Watching Our Back*/, 25694 /*Protecting Our Rear*/, 25686 /*Blood Ritual*/, 25684 /*Attune the Bloodstone*/, 25675 /*Ogre Combat*/, 25681 /*Some People Just Need Killing*/, 25680 /*That's Not Us*/, 25678 /*Pick Your Fate*/, 25677 /*It's All Mine*/, 25674 /*Futile Pride*/, 27892 /*Jurrix the Striker*/, 27893 /*Gargal, the Behemoth*/, 27891 /*Amakkar, Jack of All Trades*/, 27889 /*New Kargath*/, 27880 /*Half-Ton Holdouts*/, 27879 /*Survival of the Fattest*/, 27888 /*Return to Blam*/, 27882 /*It's Not About History, It's About Power*/, 27877 /*The Morons' League*/, 27878 /*Forcible Acquisition*/, 27774 /*Easily Swayed*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(12948, 0, 1, 0, 0, 'No payout until the fight\'s over, $g man:lady;.\n', 32750), -- The Champion of Anguish
(12936, 0, 1, 0, 0, 'No payout until the fight\'s over, $g man:lady;.', 32750), -- The Amphitheater of Anguish: Korrak the Bloodrager!
(12935, 0, 1, 0, 0, 'No payout until the fight\'s over, $g man:lady;.', 32750), -- The Amphitheater of Anguish: Tuskarrmageddon!
(12934, 0, 1, 0, 0, 'No payout until the fight\'s over, $g man:lady;.', 32750), -- The Amphitheater of Anguish: From Beyond!
(12933, 0, 1, 0, 0, 'No payout until the fight\'s over, $g man:lady;.', 32750), -- The Amphitheater of Anguish: Magnataur!
(12932, 0, 1, 0, 0, 'No payout until the fight\'s over, $g man:lady;.', 32750), -- The Amphitheater of Anguish: Yggdras!
(12903, 0, 396, 0, 0, 'There\'s nothing more I\'d want than to help you find Dargath and the twins, but I gotta stay here and guard Reed.', 32750), -- That's What Friends Are For...
(27916, 0, 0, 0, 0, 'Yes?', 0), -- Ruag's Report
(27910, 0, 0, 0, 0, 'Has Duskfang shown himself?', 32750), -- Last Regrets
(27909, 0, 0, 0, 0, 'You\'ve returned.', 32750), -- The Purespring
(27908, 0, 0, 0, 0, 'Helgrum still breathes. Do you have the mud?', 32750), -- Secrets of the Mire
(27907, 0, 0, 0, 0, 'Have you brought the prayerblossom?', 32750), -- Prayerblossom
(27857, 0, 25, 0, 0, 'There is no time! Go! Fight!', 32750), -- We're Under Attack!
(27856, 0, 0, 0, 0, 'The spirits will watch over us, $n.', 32750), -- Marking the Fallen
(27855, 0, 0, 0, 0, 'Is there a problem, $n?', 32750), -- Reinforcements Denied
(27854, 0, 25, 0, 0, 'The ogres are powerful, but without help they will fall to the Alliance riders.', 32750), -- Tides of Darkness
(27853, 0, 0, 0, 0, 'If you have a complaint about killing peasants, $r, give me a moment to spit in disgust.', 32750), -- Lumbering Oafs
(27852, 0, 25, 0, 0, 'I\'m pretty sure you still have some slaying to do.', 32750), -- Orcs and Humans
(27704, 0, 0, 0, 0, 'You must not falter, $n. Your actions will pave the way for me to enter the temple myself.', 32750), -- Legends of the Sunken Temple
(27694, 0, 0, 0, 0, 'Your gathering of these artifacts will be a sign of faith. Once rendered, I will perform the ritual.', 32750), -- Pool of Tears
(27818, 25, 25, 0, 0, 'Don\'t be squeamish now.', 32750), -- Slithering Signs
(27757, 0, 0, 0, 0, 'Getting cold feet?', 32750), -- The Darkest Depths
(27691, 0, 1, 0, 0, 'I\'ve still got a few tricks up my sleeve, but I\'m not going to tussle with murlocs if I don\'t have to.', 32750), -- Marshfin Madness
(27598, 0, 0, 0, 0, 'C\'mon, man! I\'m crazy but I\'m not stupid! Please help!', 32750), -- Kill Gil
(27656, 0, 5, 0, 0, 'Don\'t try to pull a fast one on me, pal. I know croc like nobody else.', 32750), -- Croc-Out
(28029, 0, 0, 0, 0, 'Ye used the torch already, I presume?', 32750), -- Set Them Ablaze!
(28028, 0, 274, 0, 0, 'You\'ll have to do better than that, $g lad: lass;.', 32750), -- Siege!
(27984, 0, 0, 0, 0, 'Allow me to finish my story.', 32750), -- Lunthistle's Tale
(27976, 0, 0, 0, 0, 'Did ye pound \'em?', 32750), -- Curse These Fat Fingers
(27980, 0, 0, 0, 0, 'Come on, get out there and kill those spiders!  You aren\'t afraid of money, are you?  Because that would be weird.', 32750), -- The Spiders Have to Go
(27960, 0, 0, 0, 0, 'The fewer of them that remain, the better our prospects are.', 32750), -- The Fewer, the Better
(12304, 0, 6, 0, 0, 'Why is it that I doubt your sincerity when you suggest that you\'ve done all that you can to clear the shore of those ghosts?', 32750), -- Beachfront Property
(12449, 0, 1, 0, 0, 'I started to worry that the Scourge in the shrine had claimed you. It is good that you yet live.', 32750), -- Return to the Earth
(12448, 0, 1, 0, 0, 'I\'m glad you\'re still with us, $r.', 32750), -- Heated Battle
(12144, 0, 6, 0, 0, 'Did ya finish off dose pests?', 32750), -- Pest Control
(12111, 0, 5, 0, 0, 'You must protect the wildlife from the Scourge contagion!', 32750), -- Where the Wild Things Roam
(12036, 0, 6, 0, 0, 'What\'s taking so long?', 32750), -- From the Depths of Azjol-Nerub
(28455, 0, 0, 0, 0, 'Good luck, $g brother: sister;.', 32750), -- Glory Amidst Chaos
(28451, 0, 0, 0, 0, 'What?', 0), -- A Delivery for Neeralak
(28450, 0, 0, 0, 0, 'What\'ve you got there, soldier?', 0), -- A Delivery for Thorg'izog
(28452, 0, 0, 0, 0, 'I don\'t have time for games, fool.  Get out of my sight.', 0), -- A Delivery for Xi'lun
(28448, 0, 0, 0, 0, 'You\'ve arrived, $n.', 0), -- A Deal With a Dragon
(28447, 0, 0, 0, 0, 'Come on, $n, there\'s still more of them left.  Our job isn\'t done.', 32750), -- Draconic Vanguard
(28446, 0, 0, 0, 0, 'No, I\'m not satisfied yet.  I need more blood.', 32750), -- Blood Tour
(28445, 0, 0, 0, 0, 'Any luck out there?', 32750), -- A Heap of Delicious Worg
(28444, 0, 0, 0, 0, 'The flamekin are weak, but they travel in packs.  Be cautious.', 32750), -- Latent Demons of the Land
(28443, 0, 0, 0, 0, 'The ashes of the obsidian elementals are particularly dark - exactly what we need for our purposes.', 32750), -- Blackened Ashes
(28491, 35, 35, 0, 0, 'Well?', 32750), -- Not Fireflies, Flameflies
(28439, 0, 0, 0, 0, 'Do I have to use the cudgel on you, soldier?  Get back out there!', 32750), -- I Am the Law and I Am the Lash
(28438, 0, 0, 0, 0, 'What\'s the matter, are you scared?', 32750), -- Trial by Magma
(28433, 0, 0, 0, 0, 'Oh, you\'re asking for it now, grunt.', 32750), -- Grunt Work
(28227, 0, 0, 0, 0, 'Please, help us out, $r.', 32750), -- Golem Training
(28225, 0, 0, 0, 0, 'Watch yerself, stranger...', 32750), -- Prove Yer Allegiance
(28424, 0, 0, 0, 0, 'Go ahead.  Kill him!', 32750), -- Shadow Boxing
(28418, 0, 0, 0, 0, 'I suppose you don\'t have what it takes.$b$bThat\'s fine.  I can fight this war myself.', 32750), -- Burning Vengeance
(11677, 0, 1, 0, 0, 'Either cave should do, $c. Quickly, use the seeds to end the plague!', 32750), -- Stop the Plague
(11675, 0, 1, 0, 0, 'I still see too many of them for your efforts to have been very effective. A true $c would finish the job.', 32750), -- A Proper Death
(11627, 0, 0, 0, 0, 'You still have yet to beat some sense into those two.', 32750), -- Boiling Point
(11719, 0, 5, 0, 0, 'Don\'t be afraid.', 32750), -- A Suitable Test Subject
(11611, 0, 274, 0, 0, 'No peons, no buildings. And no, we\'re not going to replace them with goblins. Too damned expensive...\n', 32750), -- Taken by the Scourge
(25720, 0, 0, 0, 0, 'I haven\'t time for this, $n.  You came here for a reason, and it wasn\'t to chat.  Get back to work.', 32750), -- The Downfall of Marl Wormthorn
(25719, 0, 0, 0, 0, 'Dawnflight\'s plan is a good one.  Do you have the vessel, $n?', 0), -- Demoniac Vessel
(25717, 0, 0, 0, 0, 'The forest is not yet cleared of the taint, $n.  Do as I say, and then we may proceed with our mission.', 32750), -- The Demons and the Druid
(25706, 0, 0, 0, 0, 'Revenge, $r friend, is my final request.', 32750), -- Neptool's Revenge
(25703, 0, 0, 0, 0, 'Strike at the naga, $r!', 32750), -- Atrocities
(25695, 0, 0, 0, 0, 'Did you get a look at those plans, $n?', 32750), -- Watching Our Back
(25694, 0, 0, 0, 0, 'You have not yet killed these demons.  $n!  Get back to the field!', 32750), -- Protecting Our Rear
(25686, 0, 0, 0, 0, 'The ritual is not yet complete.', 32750), -- Blood Ritual
(25684, 0, 0, 0, 0, 'The attunement process is simple, but will certainly come in handy down the line.', 32750), -- Attune the Bloodstone
(25675, 0, 0, 0, 0, 'The less we have to worry about ogres, the more we can focus on our true mission here.', 32750), -- Ogre Combat
(25681, 0, 0, 0, 0, 'Hondo ain\'t gonna know what hit him.', 32750), -- Some People Just Need Killing
(25680, 0, 0, 0, 0, 'What was it, mon?  You get a close enough look?', 32750), -- That's Not Us
(25678, 0, 0, 0, 0, 'Just because you\'re costing the Alliance hundreds of gold doesn\'t mean I\'m going to pay you hundreds of gold.  So don\'t even think about asking.', 32750), -- Pick Your Fate
(25677, 0, 0, 0, 0, 'I wouldn\'t store that solvent where I store my potions, if I were you.', 32750), -- It's All Mine
(25674, 0, 0, 0, 0, 'Is that ogre blood I smell?  It had better be...', 32750), -- Futile Pride
(27892, 0, 0, 0, 0, 'We\'re not quite ready yet.  A little more practice, then we\'ll get with the dragon-slaying.', 32750), -- Jurrix the Striker
(27893, 0, 0, 0, 0, 'Don\'t worry, little $r.  I\'ll protect you.', 32750), -- Gargal, the Behemoth
(27891, 0, 0, 0, 0, 'We\'re not through yet, $n.', 32750), -- Amakkar, Jack of All Trades
(27889, 0, 0, 0, 0, 'That\'s some precious cargo you carry there, $n.', 0), -- New Kargath
(27880, 0, 0, 0, 0, 'Well?  What are you waiting for?', 32750), -- Half-Ton Holdouts
(27879, 0, 0, 0, 0, 'Welcome back.', 32750), -- Survival of the Fattest
(27888, 0, 0, 0, 0, 'Well?  Has our long shot paid off?', 0), -- Return to Blam
(27882, 0, 0, 0, 0, 'You\'ve returned with liberated artifacts, I presume?', 32750), -- It's Not About History, It's About Power
(27877, 0, 0, 0, 0, '<Lidia waits expectantly.>', 32750), -- The Morons' League
(27878, 0, 0, 0, 0, 'Back so soon?', 32750), -- Forcible Acquisition
(27774, 0, 0, 0, 0, 'I\'ll feel much better when those ogres are gone.', 32750); -- Easily Swayed

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12790; -- Learning to Leave and Return: the Magical Way
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=12791; -- The Magical Kingdom of Dalaran
UPDATE `quest_request_items` SET `CompletionText`='Do you have that which is required, $n?' WHERE `ID`=12729; -- The Gods Have Spoken
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12707; -- Wooly Justice
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12708; -- Enchanted Tiki Warriors
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12709; -- Hexed Caches
UPDATE `quest_request_items` SET `CompletionText`='You\'ve returned, $n.' WHERE `ID`=12675; -- One Last Thing
UPDATE `quest_request_items` SET `CompletionText`='What seems to be the delay, $n?', `VerifiedBuild`=32750 WHERE `ID`=12665; -- I Sense a Disturbance
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=274, `VerifiedBuild`=32750 WHERE `ID`=13549; -- Tails Up
UPDATE `quest_request_items` SET `EmoteOnComplete`=274, `EmoteOnIncomplete`=274, `VerifiedBuild`=32750 WHERE `ID`=12650; -- Plundering Their Own
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=12662; -- Bringing Down Heb'Jin
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=15, `CompletionText`='Ahunae know there be no way that $n scalped that many of the Heb\'Drakkar so quickly!', `VerifiedBuild`=32750 WHERE `ID`=12659; -- Scalps!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12639; -- The Frozen Earth
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25, `CompletionText`='You have a few more of those rifts to seal before we be talkin\' again, $n.', `VerifiedBuild`=32750 WHERE `ID`=12640; -- Sealing the Rifts
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12635; -- Relics of the Snow Leopard Goddess
UPDATE `quest_request_items` SET `CompletionText`='<Zim\'Torga looks on impassively. She wonders if you seek her continued blessing by presenting more Drakkari offerings to honor her.>' WHERE `ID`=12618; -- Blessing of Zim'Torga
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12622; -- The Leaders at Jin'Alai
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12627; -- Breaking Through Jin'Alai
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12516; -- Too Much of a Good Thing
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12527; -- Gluttonous Lurkers
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12514; -- Mushroom Mixer
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=12584; -- Pure Evil
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=12555; -- A Tangled Skein
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12554; -- Malas the Corrupter
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12583; -- Crashed Sprayer
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=274, `VerifiedBuild`=32750 WHERE `ID`=12552; -- Death to the Necromagi
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12553; -- Skimmer Spinnerets
UPDATE `quest_request_items` SET `CompletionText`='Have you rescued our veterans, $n?', `VerifiedBuild`=32750 WHERE `ID`=12512; -- Leave No One Behind
UPDATE `quest_request_items` SET `CompletionText`='Have you sealed the nerubian tunnels, $n?', `VerifiedBuild`=32750 WHERE `ID`=12598; -- Throwing Down
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12562; -- The Drakkari Do Not Need Water Elementals!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12510; -- Precious Elemental Fluids
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12507; -- Strange Mojo
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12508; -- Mopping Up
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12504; -- Argent Crusade, We Are Leaving!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12505; -- New Orders for Sergeant Stackhammer
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12506; -- Trouble at the Altar of Sseratus
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12740; -- Parachutes for the Argent Crusade
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12503; -- Defend the Stand
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12914; -- Gymer's Salvation
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12713; -- Betrayal
UPDATE `quest_request_items` SET `CompletionText`='Have ya gone ta witness my creations, $n?', `VerifiedBuild`=32750 WHERE `ID`=12710; -- Disclosure
UPDATE `quest_request_items` SET `CompletionText`='Were you successful in clearing those scourgewagons, $n?', `VerifiedBuild`=32750 WHERE `ID`=12676; -- Sabotage
UPDATE `quest_request_items` SET `CompletionText`='Please, $n, tell me you haven\'t blown your cover....', `VerifiedBuild`=32750 WHERE `ID`=12669; -- So Far, So Bad
UPDATE `quest_request_items` SET `EmoteOnComplete`=274, `EmoteOnIncomplete`=274, `CompletionText`='I really don\'t know if this plan will work, $n. Just bring me the scrap metal and I\'ll do what I can.', `VerifiedBuild`=32750 WHERE `ID`=12901; -- Making Something Out Of Nothing
UPDATE `quest_request_items` SET `CompletionText`='Have you earned their commander\'s trust, $n?', `VerifiedBuild`=32750 WHERE `ID`=12661; -- Infiltrating Voltarus
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12884; -- The Ebon Watch
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12859; -- This Just In: Fire Still Hot!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12861; -- Trolls Is Gone Crazy!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12857; -- Wanted: Ragemane's Flipper
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=27663; -- Tastes Like Strider
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=7737; -- Gaining Even More Acceptance
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=13662; -- Gaining Acceptance
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=27977; -- Recon Essentials
UPDATE `quest_request_items` SET `CompletionText`='Bring me the horn, $n.', `VerifiedBuild`=32750 WHERE `ID`=27962; -- A Lumbering Relic
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12078; -- Worm Wrangler
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12080; -- Really Big Worm
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12079; -- Stomping Grounds
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12076; -- Messy Business
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12075; -- Slim Pickings
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='I remember you. You\'re not dead, so those harpy wenches better be.', `VerifiedBuild`=32750 WHERE `ID`=12052; -- Harp on This!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12050; -- Lumber Hack
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12049; -- Hard to Swallow
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `CompletionText`='Huh?  Who are you?  What do you want?\n', `VerifiedBuild`=32750 WHERE `ID`=12043; -- Nozzlerust Defense
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12045; -- Shaved Ice
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12044; -- Stocking Up
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=12469; -- Return to Sender
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=12221; -- The Forsaken Blight
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12285; -- Do Unto Others
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `CompletionText`='It\'s about time, $n! What\'s been keeping you?' WHERE `ID`=12283; -- The Truth Will Out
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12274; -- A Fall From Grace
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=12260; -- The Perfect Dissemblance
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12254; -- Without a Prayer
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=12273; -- The Denouncement
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12271; -- The Rod of Compulsion
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=12243; -- Fire Upon the Waters
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='I miss my sister, Mickey. I hope she\'s well.', `VerifiedBuild`=32750 WHERE `ID`=12240; -- A Means to an End
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12232; -- Bombard the Ballistae
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='This test will be the final experiment in the series, $n.', `VerifiedBuild`=32750 WHERE `ID`=12218; -- Spread the Good Word
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12252; -- Torture the Torturer
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12214; -- Fresh Remounts
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=12200; -- Emerald Dragon Tears
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12230; -- Stealing from the Siegesmiths
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12211; -- Let Them Not Rise!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12209; -- Materiel Plunder
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12303; -- Funding the War Effort
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=12188; -- The Forsaken Blight and You: How Not to Die
UPDATE `quest_request_items` SET `CompletionText`='Are you here to waste my time, $g boy : girl;, or did you fulfill my vendetta against the Scarlet Onslaught?', `VerifiedBuild`=32750 WHERE `ID`=12205; -- Wanted: The Scarlet Onslaught
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12206; -- Blighted Last Rites
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12267; -- Neltharion's Flame
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Power wasted on the weak and the useless.$B$BShow me a being worthy of the life and magic they have been gifted, and then perhaps we can talk of waste before extinguishing their presence.$B$BDon\'t worry, I\'ll wait.', `VerifiedBuild`=32750 WHERE `ID`=12265; -- Defiling the Defilers
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnIncompleteDelay`=60, `VerifiedBuild`=32750 WHERE `ID`=12264; -- Culling the Damned
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12261; -- No Place to Run
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnIncompleteDelay`=60, `VerifiedBuild`=32750 WHERE `ID`=12262; -- No One to Save You
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12151; -- Wanton Warlord
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=12545; -- The Cleansing Of Jintha'kalar
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12150; -- Reclusive Runemaster
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12459; -- That Which Creates Can Also Destroy
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnIncompleteDelay`=1000, `VerifiedBuild`=32750 WHERE `ID`=13343; -- Mystery of the Infinite, Redux
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12456; -- The Plume of Alystros
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='The sooner that the emerald skytalons can be dealt with, the sooner the Emerald Dragonshrine can be returned to its natural balance.', `VerifiedBuild`=32750 WHERE `ID`=12454; -- Cycle of Life
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12149; -- Mighty Magnataur
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `CompletionText`='It is good to finally meet you in person, $n. I have known you since before you were born.' WHERE `ID`=12124; -- Informing the Queen
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12450; -- Through Fields of Flame
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12470; -- Mystery of the Infinite
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12458; -- Seeds of the Lashers
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12148; -- One of a Kind
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12147; -- Disturbing Implications
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12122; -- Gaining an Audience
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12097; -- Sarathstra, Scourge of the North
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `CompletionText`='Did ya find out where dey were going?', `VerifiedBuild`=32750 WHERE `ID`=12145; -- Canyon Chase
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12017; -- Meat on the Hook
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12016; -- The Bait
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12009; -- Tua'kea's Crab Traps
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12028; -- Spiritual Insight
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11959; -- Slay Loguhn
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11958; -- Let Nothing Go To Waste
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12104; -- Return to Soar
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12136; -- The Translated Tome
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12085; -- A Letter for Home
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12096; -- Strengthen the Ancients
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12084; -- Atop the Woodlands
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12066; -- The Focus on the Beach
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12061; -- Projections and Plans
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `CompletionText`='Do not waste time, $n. Angrathar awaits!', `VerifiedBuild`=32750 WHERE `ID`=12140; -- All Hail Roanauk!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='What is it, $n? I am extremely busy.' WHERE `ID`=12069; -- Return of the High Chief
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12127; -- In Service of Frost
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=12126; -- In Service of the Unholy
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12125; -- In Service of Blood
UPDATE `quest_request_items` SET `EmoteOnComplete`=397 WHERE `ID`=12115; -- Koltira and the Language of Death
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12072; -- Blightbeasts be Damned!
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=12064; -- Chains of the Anub'ar
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12102; -- In Search of the Ruby Lilac
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12101; -- The Good Doctor...
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12005; -- Prevent the Accord
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12041; -- The Lost Empire
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `CompletionText`='It is a challenge, $n!\n', `VerifiedBuild`=32750 WHERE `ID`=12053; -- The Might of the Horde
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=12048; -- Scourge Armaments
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12040; -- An Enemy in Arthas
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12056; -- Marked for Death: High Cultist Zangus
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12091; -- Wanted: Dreadtalon
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12090; -- Wanted: Gigantaur
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=12100; -- Containing the Rot
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=12039; -- Black Blood of Yogg-Saron
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11999; -- Rifle the Bodies
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=53, `VerifiedBuild`=32750 WHERE `ID`=12033; -- Message from the West
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11983; -- Blood Oath of the Horde
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `CompletionText`='Show no mercy, $r. Slay the Anub\'ar!', `VerifiedBuild`=32750 WHERE `ID`=11980; -- Pride of the Horde
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11978; -- Into the Fold
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11898; -- Breaking Through
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11647; -- Neutralizing the Cauldrons
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11640; -- Words of Power
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11633; -- Blending In
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11630; -- The Bad Earth
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11683; -- Fallen Necropolis
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11706; -- The Collapse
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11695; -- The Horn of Elemental Fury
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=11685; -- The Heart of the Elements
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11628; -- Shrouds of the Scourge
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11909; -- Defeat the Gearmaster
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=11894; -- Patching Up
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11906; -- Cleaning Up the Pools
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11899; -- Souls of the Decursed
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11896; -- Weakness to Lightning
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11895; -- Master the Storm
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11893; -- The Power of the Elements
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11890; -- What Are They Up To?
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11684; -- Scouting the Sinkholes
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11881; -- Load'er Up!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=11887; -- Emergency Supplies
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11594; -- Put Them to Rest
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=11593; -- The Honored Dead
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11638; -- Return My Remains
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11637; -- Kaganishu
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11639; -- Revenge Upon Magmoth
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11631; -- Vision of Air
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='$n, you have returned. What did you learn?$B$BWhat is that sound?' WHERE `ID`=11629; -- Return to the Spirit Talker
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11566; -- Surrender... Not!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Do you have my spare suit, $n?' WHERE `ID`=11565; -- The Spare Suit
UPDATE `quest_request_items` SET `EmoteOnComplete`=36, `EmoteOnIncomplete`=36, `VerifiedBuild`=32750 WHERE `ID`=11564; -- Succulent Orca Stew
UPDATE `quest_request_items` SET `EmoteOnComplete`=389, `EmoteOnIncomplete`=389, `VerifiedBuild`=32750 WHERE `ID`=11563; -- Grmmurggll Mrllggrl Glrggl!!!
UPDATE `quest_request_items` SET `EmoteOnComplete`=35, `EmoteOnIncomplete`=35, `VerifiedBuild`=32750 WHERE `ID`=11569; -- Keymaster Urmgrgl
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=11560; -- Oh Noes, the Tadpoles!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=36, `VerifiedBuild`=32750 WHERE `ID`=11561; -- Them!
UPDATE `quest_request_items` SET `EmoteOnComplete`=389, `EmoteOnIncomplete`=389, `VerifiedBuild`=32750 WHERE `ID`=11559; -- Winterfin Commerce
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11571; -- Learning to Communicate
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11610; -- Leading the Ancestors Home
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11623; -- A Visit to the Curator
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11609; -- Picking Up the Pieces
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11617; -- Hampering Their Escape
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11607; -- The Lost Spirits
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='<The distant voice returns.>$B$BHave you recovered the names of the wandering elders?', `VerifiedBuild`=32750 WHERE `ID`=11605; -- The Honored Ancestors
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11612; -- Reclaiming the Quarry
UPDATE `quest_request_items` SET `CompletionText`='Have you done what I asked of you, $n?', `VerifiedBuild`=32750 WHERE `ID`=11968; -- The Tides Turn
UPDATE `quest_request_items` SET `CompletionText`='We are fighting tooth and nail, $n.  We\'ll not give these Kvaldir an inch without making them pay for it dearly.', `VerifiedBuild`=32750 WHERE `ID`=11949; -- Not Without a Fight!
UPDATE `quest_request_items` SET `CompletionText`='Have you succeeded, $n?  Our relatives in Unu\'pe are depending on your efforts.', `VerifiedBuild`=32750 WHERE `ID`=11945; -- Preparing for the Worst
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11871; -- Not On Our Watch
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11879; -- Kaw the Mammoth Destroyer
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=11867; -- Can't Get Ear-nough...
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=11868; -- The Culler Cometh
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11884; -- Nedar, Lord of Rhinos...
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='It is gruesome work that we do, $n.', `VerifiedBuild`=32750 WHERE `ID`=11869; -- Happy as a Clam
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11876; -- Help Those That Cannot Help Themselves
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11866; -- Ears of Our Enemies
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11865; -- Unfit for Death
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11951; -- Bait and Switch
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11914; -- Keep the Secret Safe
UPDATE `quest_request_items` SET `CompletionText`='Have you collected the data from Winterfin Caverns yet, $n?', `VerifiedBuild`=32750 WHERE `ID`=12728; -- Monitoring the Rift: Winterfin Cavern
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11722; -- Trophies of Gammoth
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11721; -- Gammothra the Tormentor
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=11717; -- Pollen from the Source
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=11716; -- The Wondrous Bloodspore
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11714; -- Vermin Extermination
UPDATE `quest_request_items` SET `CompletionText`='Did you defeat Gamel, $c?', `VerifiedBuild`=32750 WHERE `ID`=11619; -- Gamel the Cruel
UPDATE `quest_request_items` SET `CompletionText`='Did you succeed, $r?  The Kvaldir are cruel warriors.  Do not expect any quarter from them.', `VerifiedBuild`=32750 WHERE `ID`=11613; -- Karuk's Oath
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11711; -- Coward Delivery... Under 30 Minutes or it's Free
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=11661; -- Orabus the Helmsman
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11656; -- Burn in Effigy
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11643; -- Mobu's Pneumatic Tank Transjigamarig
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=11660; -- Horn of the Ancient Mariner
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11655; -- Into the Mist
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=11690; -- Bring 'Em Back Alive
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=11688; -- Damned Filthy Swine
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=11676; -- Merciful Freedom
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11686; -- The Warsong Farms
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11616; -- Message to Hellscream
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11615; -- Nerub'ar Secrets
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=11602; -- Cutting Off the Source
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=32750 WHERE `ID`=11608; -- Bury Those Cockroaches!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=32750 WHERE `ID`=11606; -- Patience is a Virtue that We Don't Need
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=32750 WHERE `ID`=11598; -- Taking Back Mightstone Quarry
UPDATE `quest_request_items` SET `CompletionText`='Remember, $n... this is for the good of the black dragonflight.  We are here to redeem them, not to hurt them.  This is but a step in their recovery.', `VerifiedBuild`=32750 WHERE `ID`=27771; -- Third Sample: Implanted Eggs

UPDATE `quest_request_items` SET `VerifiedBuild`=32750 WHERE `ID` IN (12730, 12712, 12684, 12674, 12668, 12672, 12666, 12646, 12632, 12597, 12606, 12599, 12610, 12609, 12557, 12799, 12596, 12690, 12686, 12677, 12673, 12664, 12904, 12652, 12648, 12629, 12637, 12630, 27600, 27599, 27536, 27592, 27587, 28032, 28030, 27979, 27981, 28099, 27961, 27964, 27958, 27963, 27956, 12047, 12046, 12234, 12031, 12013, 12006, 12089, 28226, 28423, 28421, 28420, 28419, 28417, 11641, 11907, 11649, 11961, 11969, 11957, 11931, 11919, 13414, 13413, 11943, 11936, 11910, 11900, 11912, 11918, 11671, 11648, 11590, 11582, 11576, 11587, 11625, 11644, 25705, 25699, 25698, 25697, 25692, 25691, 25687, 25690, 25685, 27789, 27766, 27765, 27776, 27775);

DELETE FROM `quest_request_items` WHERE `ID` IN (12198 /*... Or Maybe We Don't*/, 12415 /*The Horse Hollerer*/, 12430 /*The Conquest Pit: Death Is Likely*/, 12429 /*The Conquest Pit: Blood and Metal*/, 12428 /*The Conquest Pit: Mad Furbolg Fighting*/, 11264 /*Necro Overlord Mezhen*/, 11230 /*Ambushed!*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(12198, 0, 1, 0, 0, 'Did you get that golem charged? Tormak is getting impatient again...', 33941), -- ... Or Maybe We Don't
(12415, 0, 1, 0, 0, 'Have you cleared the area of horses?', 33941), -- The Horse Hollerer
(12430, 0, 0, 0, 0, 'It\'s not over until... well, you know the drift by now.', 33941), -- The Conquest Pit: Death Is Likely
(12429, 0, 0, 0, 0, 'It\'s not over until you or the metal heap tips over, friend!', 33941), -- The Conquest Pit: Blood and Metal
(12428, 0, 0, 0, 0, 'It\'s not over until you or the furbolg tips over, friend!', 33941), -- The Conquest Pit: Mad Furbolg Fighting
(11264, 0, 6, 0, 0, 'Are you sure that you killed Mezhen and his necrolords, $r?', 33941), -- Necro Overlord Mezhen
(11230, 0, 0, 0, 0, 'What are you waiting for?  Kill the Alliance scum already!', 33941); -- Ambushed!

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12099; -- Free at Last
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12094; -- Latent Power
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12199; -- Bringing Down the Iron Thane
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12203; -- Loken's Orders
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12202; -- Cultivating an Image
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12201; -- The Overseer's Shadow
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12093; -- Runes of Compulsion
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12279; -- A Bear of an Appetite
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12197; -- We Have the Power
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12204; -- In the Name of Loken
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12196; -- From the Ground Up
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12073; -- Pounding the Iron
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12058; -- The Runic Prophecies
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12054; -- Deciphering the Journal
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=12026; -- The Damaged Journal
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12070; -- Rallying the Troops
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11982; -- Raining Down Destruction
UPDATE `quest_request_items` SET `CompletionText`='It\'s good to see you, $n.', `VerifiedBuild`=33941 WHERE `ID`=12164; -- Hour of the Worg
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12165; -- An Intriguing Plan
UPDATE `quest_request_items` SET `CompletionText`='Have you taken care of the hunters in the village yet, $n?', `VerifiedBuild`=33941 WHERE `ID`=12134; -- Sasha's Hunt
UPDATE `quest_request_items` SET `CompletionText`='You\'ve returned.  Did you succeed?', `VerifiedBuild`=33941 WHERE `ID`=12236; -- Ursoc, the Bear God
UPDATE `quest_request_items` SET `CompletionText`='Have you obtained Vordrassil\'s seeds yet, $n?', `VerifiedBuild`=33941 WHERE `ID`=12242; -- Vordrassil's Seeds
UPDATE `quest_request_items` SET `CompletionText`='Have you brought me the ashes, $n?', `VerifiedBuild`=33941 WHERE `ID`=12241; -- Destroy the Sapling
UPDATE `quest_request_items` SET `CompletionText`='Yes, $n?', `VerifiedBuild`=33941 WHERE `ID`=12327; -- Out of Body Experience
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12195; -- The Unexpected 'Guest'
UPDATE `quest_request_items` SET `CompletionText`='Have you spoken to Ursoc\'s children yet, $n?', `VerifiedBuild`=33941 WHERE `ID`=12231; -- The Bear God's Offspring
UPDATE `quest_request_items` SET `CompletionText`='Have you obtained the blood samples, $n?', `VerifiedBuild`=33941 WHERE `ID`=12229; -- A Possible Link
UPDATE `quest_request_items` SET `CompletionText`='Did you obtain the dust, $n?', `VerifiedBuild`=33941 WHERE `ID`=12328; -- Ruuna's Request
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Have you done what I asked of you, $n?', `VerifiedBuild`=33941 WHERE `ID`=12213; -- The Darkness Beneath
UPDATE `quest_request_items` SET `CompletionText`='Have you obtained the samples, $n?', `VerifiedBuild`=33941 WHERE `ID`=12207; -- Vordrassil's Fall
UPDATE `quest_request_items` SET `CompletionText`='Has Jin\'arrak been defeated, $n?', `VerifiedBuild`=33941 WHERE `ID`=12152; -- Jin'arrak's End
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12113; -- Nice to Meat You
UPDATE `quest_request_items` SET `CompletionText`='Ya getter done, $n?', `VerifiedBuild`=33941 WHERE `ID`=12029; -- Seared Scourge
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11984; -- Filling the Cages
UPDATE `quest_request_items` SET `CompletionText`='Have you done what I asked of you, $n?', `VerifiedBuild`=33941 WHERE `ID`=12453; -- Eyes Above
UPDATE `quest_request_items` SET `CompletionText`='Have you completed your task yet, $n?', `VerifiedBuild`=33941 WHERE `ID`=12413; -- Attack on Silverbrook
UPDATE `quest_request_items` SET `CompletionText`='Did you complete your task?  If not, what are you doing here?', `VerifiedBuild`=33941 WHERE `ID`=12412; -- My Enemy's Friend
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12259; -- The Thane of Voldrune
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=12256; -- The Flamebinders' Secrets
UPDATE `quest_request_items` SET `CompletionText`='You get that venison yet, $n?', `VerifiedBuild`=33941 WHERE `ID`=12436; -- Supplemental Income
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=11279; -- Green Eggs and Whelps
UPDATE `quest_request_items` SET `CompletionText`='Yes, $n?' WHERE `ID`=11304; -- New Agamand
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=11504; -- The Dead Rise!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=34, `VerifiedBuild`=33941 WHERE `ID`=11182; -- Root Causes
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=274, `VerifiedBuild`=33941 WHERE `ID`=11399; -- Bring Down Those Shields
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=11398; -- It's a Scourge Device
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11298; -- What's in That Brew?
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11397; -- And You Thought Murlocs Smelled Bad!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11301; -- Brains! Brains! Brains!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='$n, you have returned. What news of Ulfang?' WHERE `ID`=11324; -- Alpha Worg
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=33941 WHERE `ID`=11317; -- The Cleansing
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=33941 WHERE `ID`=11286; -- The Artifacts of Steel Gate
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11296; -- Rivenwood Captives
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=33941 WHERE `ID`=11267; -- The Frost Wyrm and its Master
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=11266; -- Gjalerbron Attack Plans
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11433; -- Sleeping Giants
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11265; -- Of Keys and Cages
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=33941 WHERE `ID`=11263; -- Dealing With Gjalerbron
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='What news do you bring of Skorn, $n?' WHERE `ID`=11261; -- The Conqueror of Skorn!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11260; -- Stop the Ascension!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11259; -- Towers of Certain Doom
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11258; -- Burn Skorn, Burn!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11257; -- Gruesome, But Necessary
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11352; -- The Rune of Command
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11367; -- Demolishing Megalith
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11366; -- The Lodestone
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11351; -- Mastering the Runes
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11281; -- Mimicking Nature's Call
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11350; -- The Book of Runes
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11365; -- March of the Giants
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11428; -- Keeper Witherleaf
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11275; -- Making the Horn
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11311; -- Suppressing the Elements
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11271; -- Hasty Preparations
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11319; -- Seeds of the Blacksouled Keepers
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11316; -- Spawn of the Twisted Glade
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11315; -- Wild Vines
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11314; -- The Fallen Sisters
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=33941 WHERE `ID`=11313; -- Spirits of the Ice
UPDATE `quest_request_items` SET `CompletionText`='You done burning everything?  Make sure you not leave something not burned.', `VerifiedBuild`=33941 WHERE `ID`=11285; -- Baleheim Must Burn!
UPDATE `quest_request_items` SET `CompletionText`='You done with the killings yet?  Winterskorn town right across from here!', `VerifiedBuild`=33941 WHERE `ID`=11283; -- Baleheim Bodycount
UPDATE `quest_request_items` SET `CompletionText`='You kill them vrykuls?  They sure is tough!', `VerifiedBuild`=33941 WHERE `ID`=11282; -- A Lesson in Fear
UPDATE `quest_request_items` SET `CompletionText`='Are the Alliance leaders dead, $n?  Do not return until they are.', `VerifiedBuild`=33941 WHERE `ID`=11233; -- Landing the Killing Blow
UPDATE `quest_request_items` SET `CompletionText`='Have you obtained the toxin glands I seek, $n?', `VerifiedBuild`=33941 WHERE `ID`=11168; -- Spiking the Mix
UPDATE `quest_request_items` SET `CompletionText`='I don\'t care how many giants, dragons or kobolds you\'ve killed before.  Get this job done and come back when you\'re finished.', `VerifiedBuild`=33941 WHERE `ID`=11270; -- War is Hell
UPDATE `quest_request_items` SET `CompletionText`='Have you obtained the containers, $n?', `VerifiedBuild`=33941 WHERE `ID`=11167; -- The New Plague

UPDATE `quest_request_items` SET `VerifiedBuild`=33941 WHERE `ID` IN (12433, 11985, 12330, 12120, 12114, 12116, 12483, 12484, 11990, 11989, 12177, 12176, 12257, 12175, 11422, 11417, 11415, 11268, 12481, 11170, 11221, 11227);

DELETE FROM `quest_request_items` WHERE `ID` IN (13037 /*Memories of Stormhoof*/, 13051 /*Territorial Trespass*/, 13003 /*Thrusting Hodir's Spear*/, 13056 /*There's Always Time for Revenge*/, 12613 /*Powering the Waygate - The Makers' Overlook*/, 12524 /*Venture Co. Misadventure*/, 13356 /*Retest Now*/, 13215 /*Battle at Valhalas: Khit'rix the Dark Master*/, 11479 /*"Crowleg" Dan*/, 11307 /*Field Test*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(13037, 0, 1, 0, 0, 'What have you learned from spirit of Chieftain Swiftspear?', 34220), -- Memories of Stormhoof
(13051, 0, 0, 0, 0, 'Hail, $n!', 34220), -- Territorial Trespass
(13003, 0, 0, 0, 0, '', 34220), -- Thrusting Hodir's Spear
(13056, 0, 0, 0, 0, 'You find that dirty mongrel, $n?', 34220), -- There's Always Time for Revenge
(12613, 0, 0, 0, 0, 'Is it done, $n?', 34220), -- Powering the Waygate - The Makers' Overlook
(12524, 0, 1, 0, 0, 'Have you taught those thugs that we are not to be trifled with?', 34220), -- Venture Co. Misadventure
(13356, 0, 0, 0, 0, 'Well, $r? How\'d it turn out?', 34220), -- Retest Now
(13215, 0, 11, 0, 0, 'I laugh at your efforts. You are not worthy to fight here.', 34220), -- Battle at Valhalas: Khit'rix the Dark Master
(11479, 0, 0, 0, 0, 'I can\'t believe it was Dan.  Did you take care of it yet?', 34220), -- "Crowleg" Dan
(11307, 0, 0, 0, 0, 'Have you completed your field tests, $n?', 34220); -- Field Test

UPDATE `quest_request_items` SET `CompletionText`='It\'s good to see you again, $n.', `VerifiedBuild`=34220 WHERE `ID`=13035; -- Loken's Lackeys
UPDATE `quest_request_items` SET `CompletionText`='Hail, $n!  What news do you bring?', `VerifiedBuild`=34220 WHERE `ID`=13005; -- The Earthen Oath
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13058; -- Changing the Wind's Course
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13049; -- The Hero's Arms
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13048; -- Where Time Went Wrong
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13038; -- Distortions in Time
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13034; -- The Witness and the Hero
UPDATE `quest_request_items` SET `CompletionText`='Did you obtain the eggs, $n?', `VerifiedBuild`=34220 WHERE `ID`=13050; -- Veranus
UPDATE `quest_request_items` SET `CompletionText`='Have you mounted Hodir\'s Helm, $r?', `VerifiedBuild`=34220 WHERE `ID`=12987; -- Mounting Hodir's Helm
UPDATE `quest_request_items` SET `CompletionText`='Hail, sister.', `VerifiedBuild`=34220 WHERE `ID`=12997; -- Into the Pit
UPDATE `quest_request_items` SET `CompletionText`='Was your mission successful, sister?', `VerifiedBuild`=34220 WHERE `ID`=12856; -- Cold Hearted
UPDATE `quest_request_items` SET `CompletionText`='Have you survived the battle, $n?', `VerifiedBuild`=34220 WHERE `ID`=12851; -- Going Bearback
UPDATE `quest_request_items` SET `CompletionText`='Yes, $n?', `VerifiedBuild`=34220 WHERE `ID`=12971; -- Taking on All Challengers
UPDATE `quest_request_items` SET `CompletionText`='You\'re back.  Did you kill the insubordinate pig?', `VerifiedBuild`=34220 WHERE `ID`=12907; -- Examples to be Made
UPDATE `quest_request_items` SET `CompletionText`='Is it done?  I hope you didn\'t slay too many of the mongrels.  We need the manpower.', `VerifiedBuild`=34220 WHERE `ID`=12906; -- Discipline
UPDATE `quest_request_items` SET `CompletionText`='My runes, $n?  Do you have them?', `VerifiedBuild`=34220 WHERE `ID`=12841; -- The Crone's Bargain
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13274; -- The Core's Keeper
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13007; -- The Iron Colossus
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12998; -- The Heart of the Storm
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12993; -- A Colossal Threat
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=12991; -- Hit Them Where it Hurts
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12988; -- Destroy the Forges!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12984; -- Valduran the Stormborn
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=12979; -- Armor of Darkness
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12978; -- Facing the Storm
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12965; -- The Gifts of Loken
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12964; -- The Dark Ore
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12957; -- Slaves of the Stormforged
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12937; -- Relief for the Fallen
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12931; -- Fighting Back
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12930; -- Rare Earth
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13273; -- Going After the Core
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=12928; -- Norgannon's Shell
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13416; -- The Library Console
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12927; -- Data Mining
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12926; -- Pieces of the Puzzle
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12920; -- Catching up with Brann
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12917; -- Speaking with the Wind's Voice
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12895; -- The Missing Bronzebeard
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12823; -- A Flawless Plan
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12822; -- Know No Fear
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=12820; -- A Delicate Touch
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=12826; -- Slightly Unstable
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12829; -- Moving In
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12828; -- Ample Inspiration
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12827; -- Reclaimed Rations
UPDATE `quest_request_items` SET `CompletionText`='Any luck with our equipment, $n?', `VerifiedBuild`=34220 WHERE `ID`=12844; -- Equipment Recovery
UPDATE `quest_request_items` SET `CompletionText`='Did you find our men, $n?', `VerifiedBuild`=34220 WHERE `ID`=12843; -- They Took Our Men!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12818; -- Clean Up
UPDATE `quest_request_items` SET `CompletionText`='You\'ve returned, $n.' WHERE `ID`=12797; -- Back Through the Waygate
UPDATE `quest_request_items` SET `CompletionText`='You\'re back, little one.  I was beginning to worry about your well-being.', `VerifiedBuild`=34220 WHERE `ID`=12559; -- Powering the Waygate - The Makers' Perch
UPDATE `quest_request_items` SET `CompletionText`='We have little time.  The Scourge is preparing for a final push.', `VerifiedBuild`=34220 WHERE `ID`=12621; -- Freya's Pact
UPDATE `quest_request_items` SET `CompletionText`='Have you taken care of the cultists, $n?', `VerifiedBuild`=34220 WHERE `ID`=12620; -- The Lifewarden's Wrath
UPDATE `quest_request_items` SET `CompletionText`='Is it done, $n?', `VerifiedBuild`=34220 WHERE `ID`=12660; -- Weapons of Destruction
UPDATE `quest_request_items` SET `CompletionText`='Have you destroyed the trespassers, $n?', `VerifiedBuild`=34220 WHERE `ID`=12617; -- Exterminate the Intruders
UPDATE `quest_request_items` SET `CompletionText`='Have you recovered the elementals\' energy, $n?', `VerifiedBuild`=34220 WHERE `ID`=12805; -- Salvaging Life's Strength
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12579; -- Lifeblood of the Mosswalker Shrine
UPDATE `quest_request_items` SET `CompletionText`='Is it done, $n?', `VerifiedBuild`=34220 WHERE `ID`=12611; -- Returned Sevenfold
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12578; -- The Angry Gorloc
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12658; -- My Pet Roc
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12607; -- A Mammoth Undertaking
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12681; -- Reagent Agent
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12683; -- Burning to Help
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12605; -- Securing the Bait
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12603; -- Sharpening Your Talons
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=34220 WHERE `ID`=12576; -- Forced Hand
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12575; -- The Lost Mistwhisper Treasure
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=12573; -- Making Peace
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=12572; -- Gods like Shiny Things
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnIncompleteDelay`=30, `VerifiedBuild`=34220 WHERE `ID`=12538; -- The Mist Isn't Listening
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12537; -- Lightning Definitely Strikes Twice
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12536; -- A Rough Ride
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12535; -- Mischief in the Making
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12531; -- The Underground Menace
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=12532; -- Flown the Coop!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=12534; -- The Sapphire Queen
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=12533; -- The Wasp Hunter's Apprentice
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12529; -- The Ape Hunter's Slave
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12654; -- The Part-time Hunter
UPDATE `quest_request_items` SET `CompletionText`='You find anything yet, $n?', `VerifiedBuild`=34220 WHERE `ID`=12699; -- An Embarrassing Incident
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12556; -- Rhino Mastery: The Kill
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12569; -- Crocolisk Mastery: The Ambush
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12560; -- Crocolisk Mastery: The Plan
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Don\'t keep me waiting, $n. What are the results?', `VerifiedBuild`=34220 WHERE `ID`=12645; -- The Taste Test
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12551; -- Crocolisk Mastery: The Trial
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12558; -- Dreadsaber Mastery: Ready to Pounce
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12543; -- An Offering for Soo-rahm
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12634; -- Some Make Lemonade, Some Make Liquor
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12804; -- A Steak Fit for a Hunter
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12550; -- Dreadsaber Mastery: Stalking the Prey
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12592; -- The Great Hunter's Challenge
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12589; -- Kick, What Kick?
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12520; -- Rhino Mastery: The Test
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12549; -- Dreadsaber Mastery: Becoming a Predator
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12523; -- Have a Part, Give a Part
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12525; -- Wipe That Grin Off His Face
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=12522; -- Need an Engine, Take an Engine
UPDATE `quest_request_items` SET `CompletionText`='The ring, $n!  Please... tell me you\'ve found it!', `VerifiedBuild`=34220 WHERE `ID`=12624; -- It Could Be Anywhere!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13307; -- Bloodspattered Banners
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13312; -- The Ironwall Rampart
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13306; -- Raise the Barricades
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=13310; -- Assault by Air
UPDATE `quest_request_items` SET `CompletionText`='How\'d it work? Did you try it? Did you do it like I told ya?$b$bWell? Did ya?', `VerifiedBuild`=34220 WHERE `ID`=13239; -- Volatility
UPDATE `quest_request_items` SET `CompletionText`='Well, $r?$b$bDid your abomination friends prove effective?', `VerifiedBuild`=34220 WHERE `ID`=13264; -- That's Abominable!
UPDATE `quest_request_items` SET `CompletionText`='Well, $r?$b$bWhat have you learned?', `VerifiedBuild`=34220 WHERE `ID`=13237; -- Poke and Prod
UPDATE `quest_request_items` SET `CompletionText`='Well, $n?$b$bHave you got new information for me?', `VerifiedBuild`=34220 WHERE `ID`=13228; -- The Broken Front
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Stand easy, $n. What have you to report?\n' WHERE `ID`=13139; -- Into The Frozen Heart Of Northrend
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `CompletionText`='Finish them, $n!', `VerifiedBuild`=34220 WHERE `ID`=13125; -- The Air Stands Still
UPDATE `quest_request_items` SET `CompletionText`='It is a grim task, $n, but it must be done.', `VerifiedBuild`=34220 WHERE `ID`=13110; -- The Restless Dead
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=13135; -- It Could Kill Us All
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=13130; -- The Stone That Started A Revolution
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13122; -- The Scourgestone
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Do not waste time, $n.', `VerifiedBuild`=34220 WHERE `ID`=13118; -- The Purging Of Scourgeholme
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=34220 WHERE `ID`=13086; -- The Last Line Of Defense
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `CompletionText`='Don\'t give up, $n!', `VerifiedBuild`=34220 WHERE `ID`=13039; -- Defending The Vanguard
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=13040; -- Curing The Incurable
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=13008; -- Scourge Tactics
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13235; -- The Flesh Giant Champion
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13220; -- Putting Olakin Back Together Again
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13212; -- He's Gone to Pieces
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13144; -- Killing Two Scourge With One Skeleton
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13152; -- A Visit to the Doctor
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13211; -- By Fire Be Purged
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13140; -- The Runesmiths of Malykriss
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13138; -- I'm Smelting... Smelting!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13136; -- Jagged Shards
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13134; -- Spill Their Blood
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13120; -- Death's Gaze
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=13119; -- Destroying the Altars
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13117; -- Where Are They Coming From?
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13137; -- Not-So-Honorable Combat
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13133; -- Find the Ancient Hero
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13121; -- Through the Eye
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13091; -- The Art of Being a Water Terror
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13042; -- Deep in the Bowels of The Underhalls
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34220 WHERE `ID`=13092; -- Reading the Bones
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=12943; -- Shadow Vault Decree
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25, `VerifiedBuild`=34220 WHERE `ID`=12955; -- Eliminate the Competition
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=12939; -- Honor Challenge
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=34220 WHERE `ID`=12893; -- Free Your Mind
UPDATE `quest_request_items` SET `EmoteOnComplete`=25, `EmoteOnIncomplete`=25, `VerifiedBuild`=34220 WHERE `ID`=12891; -- I Have an Idea, But First...
UPDATE `quest_request_items` SET `CompletionText`='The scrolls, $n?  Did you obtain them?', `VerifiedBuild`=34220 WHERE `ID`=11423; -- The Enemy's Legacy
UPDATE `quest_request_items` SET `CompletionText`='Hail, $n.', `VerifiedBuild`=34220 WHERE `ID`=12482; -- Against Nifflevar
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=11568; -- A Return to Resting
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=11567; -- The Ancient Armor of the Kvaldir
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=34220 WHERE `ID`=11529; -- Sorlof's Booty
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=34220 WHERE `ID`=11527; -- Mutiny on the Mercy
UPDATE `quest_request_items` SET `CompletionText`='Well, $n. Did you get Jonah\'s spyglass?$B$BI can\'t just take your word for the assassination, you know? I am a pirate after all.', `VerifiedBuild`=34220 WHERE `ID`=11471; -- The Jig is Up
UPDATE `quest_request_items` SET `CompletionText`='Did you find the treasure, $n?', `VerifiedBuild`=34220 WHERE `ID`=11467; -- Dead Man's Debt
UPDATE `quest_request_items` SET `CompletionText`='Did you get what\'s mine, $n?', `VerifiedBuild`=34220 WHERE `ID`=11466; -- Jack Likes His Drink
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=11469; -- Swabbin' Soap
UPDATE `quest_request_items` SET `CompletionText`='Did you obtain my relics, $n?  Nobody gets by in this life on good looks alone... not even me!', `VerifiedBuild`=34220 WHERE `ID`=11434; -- Forgotten Treasure
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=11510; -- "Scoodles"
UPDATE `quest_request_items` SET `CompletionText`='How is your experiment going, $n?  Let me know if you have any questions behind the science involved!', `VerifiedBuild`=34220 WHERE `ID`=11306; -- Apply Heat and Stir
UPDATE `quest_request_items` SET `CompletionText`='Have you obtained the sample I require, $n?' WHERE `ID`=11305; -- A Tailor-Made Formula
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34220 WHERE `ID`=11280; -- Draconis Gastritis
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=11279; -- Green Eggs and Whelps

UPDATE `quest_request_items` SET `VerifiedBuild`=34220 WHERE `ID` IN (13010, 13006, 12975, 12981, 12985, 12967, 12994, 13559, 13011, 13001, 12915, 13064, 12996, 12989, 12983, 12900, 12968, 12942, 12925, 12970, 12969, 12980, 13055, 13000, 12882, 12821, 12831, 12830, 12819, 12836, 12546, 12547, 12691, 12580, 12561, 12571, 12644, 13367, 13366, 13358, 13355, 13278, 13279, 13351, 13277, 13142, 11476, 11464, 11455, 11458, 11457, 11456, 11310, 11424, 11309);

DELETE FROM `quest_request_items` WHERE `ID` IN (25370 /*Inciting the Elements*/, 25460 /*The Earth Rises*/, 13259 /*Establishing Superiority*/, 13329 /*Before the Gate of Horror*/, 13313 /*Blinding the Eyes in the Sky*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(25370, 0, 0, 0, 0, 'Back already, $n?', 34601), -- Inciting the Elements
(25460, 0, 0, 0, 0, 'You\'ve returned, $n.', 34601), -- The Earth Rises
(13259, 0, 0, 0, 0, 'For honor, $n.', 34601), -- Establishing Superiority
(13329, 0, 1, 0, 0, 'Have you done as I asked?', 34601), -- Before the Gate of Horror
(13313, 0, 1, 0, 0, 'Have you eliminated the Alliance\'s reconnaissance operations in the western part of the glacier?', 34601); -- Blinding the Eyes in the Sky

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=26311; -- Unfamiliar Waters
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `CompletionText`='Are we finally free of that wretched Arthas want-to-be?', `VerifiedBuild`=34601 WHERE `ID`=13164; -- The Fate of Bloodbane
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34601 WHERE `ID`=13163; -- The Rider of Blood
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34601 WHERE `ID`=13162; -- The Rider of Frost
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34601 WHERE `ID`=13161; -- The Rider of the Unholy
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Flying may be a bit more graceful, but there\'s no way that we could get in as close as the stalker can without being detected.', `VerifiedBuild`=34601 WHERE `ID`=13145; -- The Vile Hold
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='I\'m sure their new masters don\'t go easy on them, but there\'s no way these things would forget the lessons we lashed into their skins. They\'ll fear those sigils for as long as they crawl this land.', `VerifiedBuild`=34601 WHERE `ID`=13143; -- New Recruit
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=34601 WHERE `ID`=13174; -- Amidst the Confusion
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=34601 WHERE `ID`=13172; -- Seeds of Chaos
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='The options of subterfuge made available to us with the eyes are obvious. These will be very useful tools.', `VerifiedBuild`=34601 WHERE `ID`=13168; -- Parting Gifts
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13074; -- Hope Within the Emerald Nightmare
UPDATE `quest_request_items` SET `CompletionText`='Light be with you, $n.', `VerifiedBuild`=34601 WHERE `ID`=13364; -- Tirion's Gambit
UPDATE `quest_request_items` SET `CompletionText`='Did you see, $n?  Did you?', `VerifiedBuild`=34601 WHERE `ID`=13361; -- The Hunter and the Prince
UPDATE `quest_request_items` SET `CompletionText`='Did you get the dust, $n?', `VerifiedBuild`=34601 WHERE `ID`=13359; -- Where Dragons Fell
UPDATE `quest_request_items` SET `CompletionText`='Hail, $n.', `VerifiedBuild`=34601 WHERE `ID`=13349; -- Cradle of the Frostbrood
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34601 WHERE `ID`=13328; -- Shatter the Shards
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=34601 WHERE `ID`=13316; -- The Guardians of Corp'rethar

UPDATE `quest_request_items` SET `VerifiedBuild`=34601 WHERE `ID` IN (13160, 13147, 13146, 13170, 13169, 13171, 13078, 13275);

DELETE FROM `quest_request_items` WHERE `ID` IN (25551 /*The Firelord*/, 25550 /*Magma Monarch*/, 25553 /*Death to the Broodmother*/, 25555 /*The Gatekeeper*/, 25549 /*The Sanctum of the Prophets*/, 25548 /*Might of the Firelord*/, 25608 /*Slash and Burn*/, 25315 /*Graduation Speech*/, 25314 /*Speech Writing for Dummies*/, 25311 /*Twilight Territory*/, 25310 /*The Greater of Two Evils*/, 25496 /*Grudge Match*/, 25308 /*Seeds of Discord*/, 25309 /*Spiritual Training: Mercy is for the Weak*/, 25299 /*Mental Training: Speaking the Truth to Power*/, 25294 /*Walking the Dog*/, 25509 /*Physical Training: Forced Labor*/, 25330 /*Waste of Flesh*/, 25223 /*Trial By Fire*/, 25923 /*Finish Nemesis*/, 25915 /*The Strength of Tortolla*/, 25910 /*The Time for Mercy has Passed*/, 25886 /*Pressing the Advantage*/, 25901 /*Hyjal Recycling Program*/, 25904 /*The Hammer and the Key*/, 25842 /*Firefight*/, 25519 /*Children of Tortolla*/, 25514 /*Breaking the Bonds*/, 25502 /*Prepping the Soil*/, 25560 /*Egg Wave*/, 25544 /*Wave Two*/, 25525 /*Wave One*/, 25523 /*Flight in the Firelands*/, 25492 /*Firebreak*/, 25462 /*The Bears Up There*/, 25392 /*Oh, Deer!*/, 25404 /*If You're Not Against Us...*/, 25382 /*Disrupting the Rituals*/, 25381 /*Fighting Fire With ... Anything*/, 25764 /*Egg Hunt*/, 25746 /*Sethria's Brood*/, 25731 /*A Bird in Hand*/, 25664 /*A Prayer and a Wing*/, 25655 /*The Wormwing Problem*/, 25600 /*Forgemaster Pyrendius*/, 25577 /*Crushing the Cores*/, 25575 /*Forged of Shadow and Flame*/, 25576 /*Rage of the Wolf Ancient*/, 25354 /*Sweeping the Shelf*/, 25277 /*Cleaning House*/, 25272 /*Lycanthoth the Corruptor*/, 25233 /*End of the Supply Line*/, 25255 /*Harrying the Hunters*/, 25464 /*The Return of Baron Geddon*/, 25323 /*Flamebreaker*/, 25319 /*War on the Twilight's Hammer*/, 25574 /*Flames from Above*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(25551, 0, 0, 0, 0, 'Yes, $n?', 34769), -- The Firelord
(25550, 0, 0, 0, 0, 'Yes, $n?', 34769), -- Magma Monarch
(25553, 0, 0, 0, 0, 'It\'s good to see you, $n.', 34769), -- Death to the Broodmother
(25555, 0, 0, 0, 0, 'You\'ve returned, $n?', 34769), -- The Gatekeeper
(25549, 0, 66, 0, 0, 'Keep it up, $n.', 34769), -- The Sanctum of the Prophets
(25548, 0, 0, 0, 0, 'What news do you bring, $n?', 34769), -- Might of the Firelord
(25608, 0, 0, 0, 0, 'You\'ve returned, $n.', 34769), -- Slash and Burn
(25315, 0, 0, 0, 0, 'Have you come to finish me off?$B$BNo... you appear to be... sane.', 34769), -- Graduation Speech
(25314, 0, 0, 0, 0, 'Well, $n?', 34769), -- Speech Writing for Dummies
(25311, 0, 0, 0, 0, 'Is it done yet, $r?', 34769), -- Twilight Territory
(25310, 0, 0, 0, 0, 'You\'re back!', 34769), -- The Greater of Two Evils
(25496, 0, 0, 0, 0, 'Is it done, $ndamus?  Did our little champ make it out ok?', 34769), -- Grudge Match
(25308, 0, 0, 0, 0, 'Is it done yet, $n?', 34769), -- Seeds of Discord
(25309, 0, 0, 0, 0, 'Well, $ndamus.  Is it done?', 34769), -- Spiritual Training: Mercy is for the Weak
(25299, 0, 0, 0, 0, 'You\'ve returned.', 34769), -- Mental Training: Speaking the Truth to Power
(25294, 0, 0, 0, 0, 'Well... is he fed?  I\'m not taking him back unless the little monster\'s not hungry anymore.', 34769), -- Walking the Dog
(25509, 0, 0, 0, 0, 'Is it done yet, $ndamus?', 34769), -- Physical Training: Forced Labor
(25330, 0, 0, 0, 0, 'Did you find suitable servants for me, $ndamus?', 34769), -- Waste of Flesh
(25223, 0, 0, 0, 0, 'You\'ve returned.', 34769), -- Trial By Fire
(25923, 0, 6, 0, 0, 'Is Nemesis dead?', 34769), -- Finish Nemesis
(25915, 0, 6, 0, 0, 'What has the little one learned, $n?', 34769), -- The Strength of Tortolla
(25910, 0, 6, 0, 0, 'This cavern fills my lungs with heat and my eyes with ash. Are you faring any better?', 34769), -- The Time for Mercy has Passed
(25886, 0, 6, 0, 0, 'You\'ve given our forces a second wind, $n. How goes the fight?', 34769), -- Pressing the Advantage
(25901, 1, 1, 0, 0, 'Warden\'s arrows are crafted of living oak, blessed in the moonwells, and tipped with obsidian arrowheads scrawled with runes invoking the blessings of nature.$B$BThey\'re not cheap.', 34769), -- Hyjal Recycling Program
(25904, 0, 0, 0, 0, 'The glyph. Show it to me.', 34769), -- The Hammer and the Key
(25842, 0, 0, 0, 0, 'Are you there, $c? My vision is failing... I hear fighting...', 34769), -- Firefight
(25519, 0, 0, 0, 0, 'My children.$BTell me they will be born free...', 34769), -- Children of Tortolla
(25514, 0, 0, 0, 0, 'They are not of this world.$B$BThey know neither pity nor fear.', 34769), -- Breaking the Bonds
(25502, 0, 6, 0, 0, 'Are the wards up?', 34769), -- Prepping the Soil
(25560, 0, 6, 0, 0, 'Have you cracked a few eggs?$B$BI don\'t even want to know what the Twilight\'s Hammer was breeding down here...', 34769), -- Egg Wave
(25544, 0, 5, 0, 0, 'FLAP! For the love of all things merciful, flap. Flap harder!', 34769), -- Wave Two
(25525, 0, 5, 0, 0, 'Flap! Flap I say... FLAP!', 34769), -- Wave One
(25523, 0, 0, 0, 0, 'Do you feel comfortable flying yet?', 34769), -- Flight in the Firelands
(25492, 0, 1, 0, 0, 'If Hyjal is any indication of their plans for the rest of Azeroth, I shudder to think of what will happen if Twilight\'s Hammer ever gets their way.', 34769), -- Firebreak
(25462, 0, 6, 0, 0, 'Please don\'t hurt the trees. Or the bears.$B$BOr yourself.', 34769), -- The Bears Up There
(25392, 0, 1, 0, 0, 'Hurry! I can smell the smoke!', 34769), -- Oh, Deer!
(25404, 0, 1, 0, 0, 'You were sent here to talk, $r. So. Talk.', 34769), -- If You're Not Against Us...
(25382, 0, 6, 0, 0, 'Tell me... have you found the fiends responsible for this?', 34769), -- Disrupting the Rituals
(25381, 0, 6, 0, 0, 'You\'re covered in soot. Are we winning the fight out there?', 34769), -- Fighting Fire With ... Anything
(25764, 0, 0, 0, 0, '', 34769), -- Egg Hunt
(25746, 0, 6, 0, 0, 'Have you delivered a message?$B$BBe sure to take flight, too, and hunt Sethria\'s minions on the other ledges.', 34769), -- Sethria's Brood
(25731, 0, 1, 0, 0, 'Marion used to visit the shrine here. Skylord Omnuron tried to give the harpies the benefit of the doubt, but I never trusted her. ', 34769), -- A Bird in Hand
(25664, 1, 1, 0, 0, 'Don\'t trouble yourself over Blaithe\'s condition. Grief robbed that creature of a soul epochs ago. He was but a shell of his former self, a beast of pure rage.', 34769), -- A Prayer and a Wing
(25655, 0, 6, 0, 0, 'Have you helped thin their numbers, $c?', 34769), -- The Wormwing Problem
(25600, 0, 6, 0, 0, 'Is Pyrendius dead? This ashen heat of this cave is suffocating me!', 34769), -- Forgemaster Pyrendius
(25577, 0, 6, 0, 0, 'Are they dead?$B$BIt seems like nothing we do can cool this inferno...', 34769), -- Crushing the Cores
(25575, 0, 6, 0, 0, 'So. Have you done any damage?', 34769), -- Forged of Shadow and Flame
(25576, 0, 6, 0, 0, 'It\'s okay to revel in the destruction of deserving foes, $c. How goes the fight?', 34769), -- Rage of the Wolf Ancient
(25354, 0, 6, 0, 0, 'How goes the fight? I need not tell you how uneasy it makes me to have the Hammer\'s agents lurking above our heads.', 34769), -- Sweeping the Shelf
(25277, 0, 6, 0, 0, 'How goes the ogre hunting?', 34769), -- Cleaning House
(25272, 1, 0, 0, 0, 'Your bravery is an inspiration to others, $c. Tell me your name. ', 0), -- Lycanthoth the Corruptor
(25233, 0, 1, 0, 0, 'Every supply caravan we stop in its tracks will lead to more victories on the front.', 34769), -- End of the Supply Line
(25255, 0, 6, 0, 0, 'How goes the fight below?', 34769), -- Harrying the Hunters
(25464, 0, 0, 0, 0, 'Is it done yet, $n?', 34769), -- The Return of Baron Geddon
(25323, 0, 0, 0, 0, 'Is it done, $n?', 34769), -- Flamebreaker
(25319, 0, 0, 0, 0, 'Is it done, $n?', 34769), -- War on the Twilight's Hammer
(25574, 0, 0, 0, 0, 'Is it done yet, $n?', 34769); -- Flames from Above

UPDATE `quest_request_items` SET `CompletionText`='Did you succeed in your task, $n?', `VerifiedBuild`=34769 WHERE `ID`=25554; -- Secrets of the Flame
UPDATE `quest_request_items` SET `CompletionText`='Did you get the documents, $n?', `VerifiedBuild`=34769 WHERE `ID`=25296; -- Gather the Intelligence
UPDATE `quest_request_items` SET `CompletionText`='Yes, $ndamus?', `VerifiedBuild`=34769 WHERE `ID`=25224; -- In Bloom
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='I am at my wit\'s end, $n! Aessina is silent.$B$BHave you found something? What is this?' WHERE `ID`=25372; -- Aessina's Miracle
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34769 WHERE `ID`=25507; -- Hell's Shells
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=34769 WHERE `ID`=25493; -- Fresh Bait
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=34769 WHERE `ID`=25428; -- Black Heart of Flame
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34769 WHERE `ID`=25408; -- Seeds of Their Demise
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=34769 WHERE `ID`=25385; -- Save the Wee Animals
UPDATE `quest_request_items` SET `EmoteOnComplete`=274, `EmoteOnIncomplete`=274, `VerifiedBuild`=34769 WHERE `ID`=25776; -- Sethria's Demise
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=34769 WHERE `ID`=25761; -- Disassembly
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=34769 WHERE `ID`=25758; -- A Gap in Their Armor
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=34769 WHERE `ID`=25599; -- Cindermaul, the Portal Master
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=34769 WHERE `ID`=25298; -- Free Your Mind, the Rest Follows
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=34769 WHERE `ID`=25270; -- Howling Mad
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='Have you created some havoc down there, $n?', `VerifiedBuild`=34769 WHERE `ID`=25234; -- In the Rear With the Gear
UPDATE `quest_request_items` SET `CompletionText`='The key, $n.  Did you get it?', `VerifiedBuild`=34769 WHERE `ID`=25321; -- Twilight Captivity
UPDATE `quest_request_items` SET `CompletionText`='Yes, $n?', `VerifiedBuild`=34769 WHERE `ID`=25472; -- The Flameseer's Staff

UPDATE `quest_request_items` SET `VerifiedBuild`=34769 WHERE `ID` IN (25552, 25494, 25274, 25491, 25656, 25355, 25303, 25328, 25297);

DELETE FROM `quest_request_items` WHERE `ID` IN (26142 /*Ascend No More!*/, 26133 /*Fiends from the Netherworld*/, 26130 /*Unplug L'ghorek*/, 26065 /*Free Wil'hai*/, 26072 /*Into the Totem*/, 26071 /*Clearing the Defiled*/, 25980 /*A Standard Day for Azrajar*/, 25974 /*Sira'kess Slaying*/, 26091 /*Here Fishie Fishie 2: Eel-Egg-Trick Boogaloo*/, 26089 /*Die Fishman Die*/, 26126 /*The Perfect Fuel*/, 25951 /*Final Judgment*/, 25629 /*Her Lady's Hand*/, 25896 /*Devout Assembly*/, 26135 /*Visions of the Past: Rise from the Deep*/, 25972 /*Honor and Privilege*/, 25861 /*Setting An Example*/, 25859 /*No Trespass Forgiven*/, 25966 /*Visions of the Past: The Slaughter of Biel'aran Ridge*/, 25965 /*Gauging Success*/, 25963 /*Swift Action*/, 25960 /*Not Entirely Unprepared*/, 25959 /*Clear Goals*/, 25658 /*Built to Last*/, 25619 /*Reoccupation*/, 25957 /*Visions of the Past: The Invasion of Vashj'ir*/, 25954 /*An Occupation of Time*/, 25952 /*Caught Off-Guard*/, 25955 /*A Better Vantage*/, 25953 /*Swift Approach*/, 25593 /*Shelled Salvation*/, 25592 /*Deep Attraction*/, 25993 /*Body Blows*/, 25990 /*Breaking Through*/, 25908 /*Stick it to Them*/, 25907 /*Slave Labor*/, 25900 /*Making Contact*/, 25440 /*Fathom-Lord Zin'jatar*/, 25439 /*Vengeful Heart*/, 25441 /*Vortex*/, 25360 /*Crabby Patrons*/, 25215 /*A Distracting Scent*/, 25220 /*Slippery Threat*/, 25221 /*Rundown*/, 25164 /*Backed Into a Corner*/, 25334 /*The Looming Threat*/, 25883 /*How Disarming*/, 26008 /*Decompression*/, 25884 /*Come Hell or High Water*/, 26040 /*What? What? In My Gut...?*/, 25887 /*Wake of Destruction*/, 26007 /*Debriefing*/, 25503 /*Blackfin's Booty*/, 25467 /*Kliklak's Craw*/, 25657 /*Dah, Nunt... Dah, Nunt...*/, 25794 /*Undersea Sanctuary*/, 25459 /*Ophidophobia*/, 25371 /*The Abyssal Ride*/, 25598 /*Ain't Too Proud to Beg*/, 25942 /*Buy Us Some Time*/, 25936 /*Pay It Forward*/, 25929 /*Sea Legs*/, 27136 /*Elemental Energy*/, 26245 /*Gunship Down*/, 27008 /*Fly Over*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(26142, 0, 0, 0, 0, 'I GROW WEAKER. YOU MUST DESTROY... MORE CONDUITS BEFORE... I DIE.', 35435), -- Ascend No More!
(26133, 0, 1, 0, 0, 'Not all of the fiends have been destroyed.', 35435), -- Fiends from the Netherworld
(26130, 0, 25, 0, 0, 'You must slay each of those ogre magi to stop their rituals and disconnect L\'ghorek from the one below.', 35435), -- Unplug L'ghorek
(26065, 0, 6, 0, 0, 'Wil\'hai is still trapped.', 35435), -- Free Wil'hai
(26072, 0, 6, 0, 0, 'Is the totem full?', 35435), -- Into the Totem
(26071, 0, 25, 0, 0, 'Go back down there and kill more of those things.', 35435), -- Clearing the Defiled
(25980, 0, 25, 0, 0, 'First you need to kill Azrajar. Then, you take the pointy end of the banner and you stick it in him.', 35435), -- A Standard Day for Azrajar
(25974, 0, 1, 0, 0, 'This isn\'t going to be easy, but when they\'re dead, we\'ll have ourselves a strong drink.$B$BRight?', 35435), -- Sira'kess Slaying
(26091, 0, 0, 0, 0, 'Save my wolf, $n.', 35435), -- Here Fishie Fishie 2: Eel-Egg-Trick Boogaloo
(26089, 0, 0, 0, 0, 'Kill those fish-men, $n.', 35435), -- Die Fishman Die
(26126, 0, 0, 0, 0, 'We haven\'t found the right combination yet, $n.  Keep at it!  I\'m sure you can figure it out!', 35435), -- The Perfect Fuel
(25951, 0, 1, 0, 0, 'Stand with us, Battlemaiden. We shall not fall this day.', 35435), -- Final Judgment
(25629, 0, 0, 0, 0, 'I dispatched my Honor Guard when the fighting broke out. They are better equipped to deal with the chaos of this kind of battle, and I am hardly in need of their aid.', 35435), -- Her Lady's Hand
(25896, 0, 1, 0, 0, 'The threat may not be sure, but the Kvaldir are certainly not fools. They would not return if they did not have some confidence in victory.$B$BThe sooner our allies are summoned, the better. Find my Tide Priestesses.', 35435), -- Devout Assembly
(26135, 0, 1, 0, 0, 'The ruins are surely still swarming with naga. Pay close attention to their patrols and I\'m sure you\'ll be able to slip through.', 35435), -- Visions of the Past: Rise from the Deep
(25972, 0, 1, 0, 0, 'Those aren\'t trade ships, those are war ships. Still, this is an incredible stroke of luck. Fire that flare off and pray that they see it.', 35435), -- Honor and Privilege
(25861, 0, 1, 0, 0, 'If your ladyship has the time, bring a high-shaman to my feet that I might deliver a message to him and his people.', 35435), -- Setting An Example
(25859, 0, 1, 0, 0, 'Look. It\'s my job to guard the bridge. It may not be a glorious job, but it\'s the only one I have right now.$B$BGo find some Kvaldir to kill off in those ruins and leave this little slice of heaven to me. ', 35435), -- No Trespass Forgiven
(25966, 0, 1, 0, 0, 'I know it\'s a hard request to head - a whim in a time of dire consequences. You just have to trust me. More than anything right know, we need to know why the naga are here and what they are capable of.', 35435), -- Visions of the Past: The Slaughter of Biel'aran Ridge
(25965, 0, 6, 0, 0, 'Any word... on their numbers?', 35435), -- Gauging Success
(25963, 0, 1, 0, 0, 'Speak to Fiasco Sizzlegrin to secure a mount for the assault.', 35435), -- Swift Action
(25960, 0, 0, 0, 0, 'Finished already?', 35435), -- Not Entirely Unprepared
(25959, 0, 0, 0, 0, 'They\'re amassing infantry to the south.$B$BWe need more time. Do anything you can to clear them out.', 35435), -- Clear Goals
(25658, 0, 1, 0, 0, 'The High Priestess sends her thanks for agreeing to aid us in our duties.', 35435), -- Built to Last
(25619, 0, 1, 0, 0, 'I had heard tales of the fierceness of these Kvaldir, but so far, the boasts seem empty.', 35435), -- Reoccupation
(25957, 0, 6, 0, 0, 'That took longer than expected. Did you learn anything useful? Who did the blade belong to?', 35435), -- Visions of the Past: The Invasion of Vashj'ir
(25954, 0, 1, 0, 0, 'Let\'s keep the Captain out of this, shall we? That man has only vengeance on his mind, and his eyes are locked forward. The past is meaningless to him.', 35435), -- An Occupation of Time
(25952, 0, 1, 0, 0, 'This is a matter of life and death, $c. The longer we wait, the more we risk giving away our position.', 35435), -- Caught Off-Guard
(25955, 0, 0, 0, 0, 'We are not hard to find in this cave. We will need to strike quickly - before the naga start searching for us.', 35435), -- A Better Vantage
(25953, 0, 1, 0, 0, 'It seems clear that they do not take us seriously, which actually worries me. We have no idea how many of these naga there really are. As time passes, I grow to fear that the shell we escaped was only a small piece of a very large puzzle.', 35435), -- Swift Approach
(25593, 0, 1, 0, 0, 'We need to get back on feet quickly, before the rest of the naga find us.', 35435), -- Shelled Salvation
(25592, 0, 1, 0, 0, 'I don\'t know how long the men up there can hold out. Between exhaustion, limited air, and those murlocs, they\'re going to get worn down quickly.', 35435), -- Deep Attraction
(25993, 0, 0, 0, 0, 'You\'d better keep trying, $n.  These naga aren\'t going anywhere unless you wake the creature up.', 35435), -- Body Blows
(25990, 0, 0, 0, 0, 'The ritual is not yet complete, $n.', 35435), -- Breaking Through
(25908, 0, 0, 0, 0, '<Duarn is too focused on his task to notice your presence.>', 35435), -- Stick it to Them
(25907, 0, 0, 0, 0, 'I need more time, $n...', 35435), -- Slave Labor
(25900, 0, 0, 0, 0, 'Nespirah needs our help.  If nothing else, I can sense that.', 35435), -- Making Contact
(25440, 0, 1, 0, 0, 'Waiting on something? I thought you\'d appreciate the opportunity to handle this yourself.$B$BDid I misjudge you?', 35435), -- Fathom-Lord Zin'jatar
(25439, 0, 0, 0, 0, 'These naga have ignited a fire in me that is not easily quenched.', 35435), -- Vengeful Heart
(25441, 0, 1, 0, 0, 'Yes, $r?', 35435), -- Vortex
(25360, 0, 1, 0, 0, 'Careful. They pinch.', 35435), -- Crabby Patrons
(25215, 0, 0, 0, 0, 'We are they prey to many of the creatures in these waters. We cannot let our guard down.', 35435), -- A Distracting Scent
(25220, 0, 1, 0, 0, 'You look relatively intact. Have you finished?', 35435), -- Slippery Threat
(25221, 0, 1, 0, 0, 'Our other allies are in the cave below. Things look safe from here, but it\'s hard to be certain.$B$BDid you do as I asked of you?', 35435), -- Rundown
(25164, 0, 1, 0, 0, 'Dey seem relentless, but we gonna turn dem back!', 35435), -- Backed Into a Corner
(25334, 0, 1, 0, 0, 'Lose yaself in the dancin\' flames. Come with me, deeper into Vashj\'ir, so that we be knowin\' the face of our enemy.', 35435), -- The Looming Threat
(25883, 0, 0, 0, 0, 'Have you destroyed the naga arsenal?', 35435), -- How Disarming
(26008, 0, 0, 0, 0, 'Were you able to rescue some of the imprisoned warriors, $n?', 35435), -- Decompression
(25884, 0, 0, 0, 0, 'You fill the sea with naga blood yet, $r?', 35435), -- Come Hell or High Water
(26040, 0, 0, 0, 0, 'Were you able to find me any of their seaweed, $r?', 35435), -- What? What? In My Gut...?
(25887, 0, 0, 0, 0, 'With the naga numbers dramatically lessened, we shall be able to finish our destruction of this stronghold.', 35435), -- Wake of Destruction
(26007, 0, 0, 0, 0, 'That\'s it, $r.$b$bThat\'s all I know...', 35435), -- Debriefing
(25503, 0, 0, 0, 0, 'You\'ve discovered Gilblingle\'s family treasure!', 0), -- Blackfin's Booty
(25467, 0, 0, 0, 0, 'The footlocker\'s keyhole is encrusted with barnacles, but may still be operable.', 0), -- Kliklak's Craw
(25657, 0, 0, 0, 0, 'Well? Is Gnaws dead, $r?', 35435), -- Dah, Nunt... Dah, Nunt...
(25794, 0, 0, 0, 0, 'Have you familiarized yourself with the cavern\'s location, $n?', 35435), -- Undersea Sanctuary
(25459, 0, 0, 0, 0, 'You take care of those snakes for me, $c?', 35435), -- Ophidophobia
(25371, 0, 1, 0, 0, 'The grace of these creatures is astounding. They will make the perfect mounts.', 35435), -- The Abyssal Ride
(25598, 0, 0, 0, 0, 'Well, $n? Did you find them?', 35435), -- Ain't Too Proud to Beg
(25942, 0, 0, 0, 0, 'You give those scaly scum something to think about, $r?', 35435), -- Buy Us Some Time
(25936, 0, 0, 0, 0, 'Were you able to rescue the warriors, $r?$b$bWe will perish without their help...', 35435), -- Pay It Forward
(25929, 0, 0, 0, 0, 'Were you able to gather the items I requested, $r?', 35435), -- Sea Legs
(27136, 0, 0, 0, 0, 'Yes, $n?', 35435), -- Elemental Energy
(26245, 0, 0, 0, 0, 'Did you find out what happened to the Storm\'s Fury?', 35435), -- Gunship Down
(27008, 0, 6, 0, 0, 'What did you see? What are the Twilight\'s Hammer doing at the Masters\' Gate?', 35435); -- Fly Over

UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='Do you have it, $n?$B$BWith the Unfathomable\'s brain, we still may yet be able to communicate with L\'ghorek, the dying ancient one in front of us.', `VerifiedBuild`=35435 WHERE `ID`=26111; -- ... It Will Come
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=35435 WHERE `ID`=26096; -- Scalding Shrooms
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='How much plunder did you get, $n?', `VerifiedBuild`=35435 WHERE `ID`=25976; -- Treasure Reclamation
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=35435 WHERE `ID`=25982; -- Those Aren't Masks
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=35435 WHERE `ID`=25964; -- Fallen But Not Forgotten
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `VerifiedBuild`=35435 WHERE `ID`=25962; -- Properly Inspired
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25956; -- Upon the Scene of Battle
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=35435 WHERE `ID`=25594; -- Crafty Crabs
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=35435 WHERE `ID`=25595; -- Something Edible
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=25442; -- A Pearl of Wisdom
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=35435 WHERE `ID`=25218; -- Undersea Inflation
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=35435 WHERE `ID`=25219; -- Don't be Shellfish
UPDATE `quest_request_items` SET `CompletionText`='You\'ve returned, $n.', `VerifiedBuild`=35435 WHERE `ID`=26244; -- The Earth Claims All
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=27005; -- The Twilight Plot

UPDATE `quest_request_items` SET `VerifiedBuild`=35435 WHERE `ID` IN (26141, 26088, 26087, 26122, 25971, 25970, 25659, 25994, 25992, 25989, 25732, 25651, 25358, 25602, 25389, 25390, 25477, 25947, 25944, 25943, 28805);

DELETE FROM `quest_request_items` WHERE `ID` IN (26836 /*Rescue the Stonefather... and Flint*/, 26792 /*Fungal Monstrosities*/, 26791 /*Sprout No More*/, 26770 /*Mystic Masters*/, 26762 /*Reactivate the Constructs*/, 26755 /*Keep Them off the Front*/, 26591 /*Battlefront Triage*/, 26537 /*Shatter Them!*/, 26502 /*Thunder Stones*/, 26500 /*We're Surrounded*/, 26499 /*Stonefather's Boon*/, 27932 /*The Axe of Earthly Sundering*/, 27043 /*Fight Fire and Water and Air with...*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(26836, 0, 25, 0, 0, 'You must rescue Stonefather Oremantle. There\'s no time to waste, $n!', 35662), -- Rescue the Stonefather... and Flint
(26792, 0, 1, 0, 0, 'We need more of those monstrosities destroyed, $n.', 35662), -- Fungal Monstrosities
(26791, 0, 1, 0, 0, 'Don\'t forget to use the war guardian to help you. The chasm is teeming with mystics and fungal monstrosities.', 35662), -- Sprout No More
(26770, 0, 6, 0, 0, 'Do I have to go in there and do it myself, $n?', 35662), -- Mystic Masters
(26762, 0, 1, 0, 0, 'We\'ll need a few more reactivated. The last thing we want is to have to face our own constructs on top of all of this!', 35662), -- Reactivate the Constructs
(26755, 0, 5, 0, 0, 'Get back in a catapult and put those things back in the ground. The line\'s barely holding!', 35662), -- Keep Them off the Front
(26591, 0, 1, 0, 0, 'There are more injured Earthen on the front.', 35662), -- Battlefront Triage
(26537, 0, 25, 0, 0, 'I need you to shatter a few more, $n.', 35662), -- Shatter Them!
(26502, 6, 0, 1000, 0, '<The older Earthen has cracks where the others do not, clearly ancient.>$B$BWhat are you supposed to be? Some kind of fleshy mistake? Cursed is what you are!$B$B<Clay spits dust.>$B$BMake yourself useful or get off of my front!', 0), -- Thunder Stones
(26500, 0, 25, 0, 0, 'Are you going to pull your fleshy weight, $r?', 35662), -- We're Surrounded
(26499, 0, 1, 0, 0, 'Rally more of our troops, $n.', 35662), -- Stonefather's Boon
(27932, 0, 25, 0, 0, 'We need more of those giants destroyed, $n.', 35662), -- The Axe of Earthly Sundering
(27043, 0, 6, 0, 0, 'Have you not managed to gain the elemental wards and defeat Haethen Kaul yet?', 35662); -- Fight Fire and Water and Air with...

UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=27938; -- The Middle Fragment
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=27126; -- Rush Delivery
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=35662 WHERE `ID`=26625; -- Troggzor the Earthinator
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=35662 WHERE `ID`=26564; -- Fixer Upper
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=35662 WHERE `ID`=27933; -- Elemental Ore
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=27005; -- The Twilight Plot
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=35662 WHERE `ID`=27135; -- Something that Burns
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=35662 WHERE `ID`=26410; -- Explosive Bonding Compound

DELETE FROM `quest_request_items` WHERE `ID` IN (27747 /*Total War*/, 27929 /*Drag 'em Down*/, 27622 /*Mo' Better Shredder*/, 27611 /*Blood on the Sand*/, 27610 /*Scouting the Shore*/, 27606 /*Blast Him!*/, 27584 /*Blood in the Surf*/, 26830 /*Traitor's Bait*/, 26621 /*Insurrection*/, 26538 /*Emergency Aid*/, 26374 /*Ready the Ground Troops*/, 26831 /*The Twilight Flight*/, 26832 /*Therazane's Mercy*/, 26829 /*The Stone March*/, 26827 /*Rallying the Earthen Ring*/, 26583 /*Wrath of the Fungalmancer*/, 26584 /*Shaken and Stirred*/, 26581 /*A Head Full of Wind*/, 26579 /*Gone Soft*/, 26578 /*Doomshrooms*/, 26659 /*Resonating Blow*/, 26657 /*Hard Falls*/, 26656 /*Don't. Stop. Moving.*/, 26575 /*Rock Bottom*/, 26439 /*Putting the Pieces Together*/, 26438 /*Intervention*/, 26426 /*Violent Gale*/, 26375 /*Loose Stones*/, 26377 /*Unsolid Ground*/, 26376 /*Hatred Runs Deep*/, 26315 /*Imposing Confrontation*/, 26314 /*On Even Ground*/, 26312 /*Crumbling Defenses*/, 26857 /*Abyssion's Minions*/, 26861 /*Block the Gates*/, 26771 /*Testing the Trap*/, 26261 /*Question the Slaves*/, 26258 /*Deathwing's Fall*/, 26254 /*Some Spraining to Do*/, 26251 /*Take No Prisoners*/, 26250 /*On Second Thought, Take One Prisoner*/, 26248 /*All Our Friends Are Dead*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(27747, 0, 6, 0, 0, 'I trust you set the entire ridge aflame?', 36322), -- Total War
(27929, 0, 6, 0, 0, 'Have you helped clear the skies, $n?', 36322), -- Drag 'em Down
(27622, 0, 6, 0, 0, 'Is my salvage expert still alive? More importantly... is my shredder?', 36322), -- Mo' Better Shredder
(27611, 0, 6, 0, 0, 'How goes the defense of our beach head?', 36322), -- Blood on the Sand
(27610, 0, 0, 0, 0, 'What\'s the state of the beach head, $n?', 36322), -- Scouting the Shore
(27606, 0, 1, 0, 0, 'You want me to keep firing?$B$BI can keep firing.', 36322), -- Blast Him!
(27584, 0, 5, 0, 0, 'After the battle we will mount their heads on pikes and build a wall all along the beach. THAT will show these belly-crawling SNAKES who owns the Highlands.', 36322), -- Blood in the Surf
(26830, 0, 6, 0, 0, 'It is good to see you, $c. How goes the search?', 36322), -- Traitor's Bait
(26621, 0, 5, 0, 0, 'Revolution, at last!$B$BThe Dragonmaw are finally undoing the shackles of the filth who have held us back!', 36322), -- Insurrection
(26538, 0, 274, 0, 0, 'Speak quickly! What do you want?$B$BDon\'t let the Warchief see us talking...', 36322), -- Emergency Aid
(26374, 0, 6, 0, 0, 'Have you found my missing troops?$B$BBe sure to search every filthy back-alley. If there\'s trouble, they\'ll find it.', 36322), -- Ready the Ground Troops
(26831, 0, 1, 0, 0, 'It is good to see you on the battlefield again.', 36322), -- The Twilight Flight
(26832, 0, 1, 0, 0, 'You\'ve not yet completed the task that I set upon you - I have no further words to offer you.', 36322), -- Therazane's Mercy
(26829, 0, 1, 0, 0, 'Our revenge against the worshipers of Deathwing has finally arrived. It is a sweet revenge.', 36322), -- The Stone March
(26827, 0, 0, 0, 0, '', 36322), -- Rallying the Earthen Ring
(26583, 0, 1, 0, 0, 'I cannot fit inside. Our elementals are not up to the task.$B$BYou must see this done.', 36322), -- Wrath of the Fungalmancer
(26584, 0, 1, 0, 0, 'Strangely, your size and resourcefulness are starting to prove quite useful.', 36322), -- Shaken and Stirred
(26581, 0, 1, 0, 0, 'The fighting at the temple has quieted since you left. Whatever impression you\'re making, it seems to have helped at least that much.', 36322), -- A Head Full of Wind
(26579, 0, 1, 0, 0, 'We have escaped the curse of flesh for this long; I will not see my brothers fall to such weaknesses now.', 36322), -- Gone Soft
(26578, 0, 0, 0, 0, 'I am not yet convinced that you have more value than the filth I have sent you to cleanse.', 36322), -- Doomshrooms
(26659, 0, 1, 0, 0, 'This broodmother has taken wing over these stone drakes for nearly 300 years. She is quite strong, even for a stone dragon.', 36322), -- Resonating Blow
(26657, 0, 0, 0, 0, 'Look to the dragons that have been knocked out of the sky by boulders. They will be easier targets.', 36322), -- Hard Falls
(26656, 0, 0, 0, 0, 'Did they make it, $c?', 36322), -- Don't. Stop. Moving.
(26575, 0, 0, 0, 0, 'Rough times, these...', 36322), -- Rock Bottom
(26439, 0, 0, 0, 0, '<Berracite grumbles, and you feel the reverberations gradually roll by under your feet.>', 36322), -- Putting the Pieces Together
(26438, 0, 0, 0, 0, 'I do not know why the flayers hunger so. Many things have changed since the rift opened between our worlds.', 36322), -- Intervention
(26426, 0, 0, 0, 0, '', 36322), -- Violent Gale
(26375, 0, 0, 0, 0, 'It is unbearable to watch. They know no mercy. They should be offered none.', 36322), -- Loose Stones
(26377, 0, 0, 0, 0, 'BThey will learn respect for the earth...$B$BPiece by piece...$B$BRock by rock...$B$B...with time.', 36322), -- Unsolid Ground
(26376, 0, 1, 0, 0, 'Take your time, fleshling.$B$BI am in no hurry.', 36322), -- Hatred Runs Deep
(26315, 0, 6, 0, 0, 'Did ya confront Boden yet?', 36322), -- Imposing Confrontation
(26314, 0, 0, 0, 0, 'Did it work, mon?', 36322), -- On Even Ground
(26312, 0, 1, 0, 0, 'Perhaps it was foolish of me to let dem be pressin\' out so far. Everythin\' I know of da earth elementals told me an attack like dis couldn\'t be lastin\'... dat dey were just lashin\' out in dere rage, and would be leavin\' just as quickly.$B$BIt be very clear now dat I was wrong.', 36322), -- Crumbling Defenses
(26857, 0, 0, 0, 0, 'Did you succeed, $n?', 36322), -- Abyssion's Minions
(26861, 0, 0, 0, 0, 'You\'ve returned, $n.  Are the gates closed?', 36322), -- Block the Gates
(26771, 0, 0, 0, 0, 'It seems like the trap will work on Abyssion.', 36322), -- Testing the Trap
(26261, 0, 0, 0, 0, 'What have we discovered?', 36322), -- Question the Slaves
(26258, 0, 0, 0, 0, 'Yes, $n?', 36322), -- Deathwing's Fall
(26254, 0, 0, 0, 0, 'Yes, $n?', 36322), -- Some Spraining to Do
(26251, 0, 0, 0, 0, 'Is it done, $n?', 36322), -- Take No Prisoners
(26250, 0, 0, 0, 0, 'Hail, $n.', 36322), -- On Second Thought, Take One Prisoner
(26248, 0, 0, 0, 0, 'The spirits always have something to say to those who will listen.', 36322); -- All Our Friends Are Dead

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=27750; -- War Forage
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=27751; -- Crushing the Wildhammer
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=36322 WHERE `ID`=27586; -- Shells on the Sea Shore
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=36322 WHERE `ID`=26784; -- Muddied Waters
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=36322 WHERE `ID`=26788; -- Cementing Our Victory
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=26540; -- Dangerous Compassion
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='$n, I understand you\'re going to speak with our \"Warchief\" about joining your Horde.$B$BBe careful, $c.$B$BSee me afterwards... ', `VerifiedBuild`=36322 WHERE `ID`=26549; -- Madness
UPDATE `quest_request_items` SET `EmoteOnComplete`=273, `EmoteOnIncomplete`=273, `VerifiedBuild`=36322 WHERE `ID`=26361; -- Smoot's Samophlange
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=36322 WHERE `ID`=26875; -- Undying Twilight
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=36322 WHERE `ID`=26585; -- Corruption Destruction
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=36322 WHERE `ID`=26658; -- Fragile Values
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=36322 WHERE `ID`=26313; -- Core of Our Troubles
UPDATE `quest_request_items` SET `CompletionText`='$n!  You\'ve returned!' WHERE `ID`=26876; -- The World Pillar Fragment
UPDATE `quest_request_items` SET `CompletionText`='We must make haste if we\'re to rebuild the World Pillar, $n.', `VerifiedBuild`=36322 WHERE `ID`=26256; -- Bleed the Bloodshaper
UPDATE `quest_request_items` SET `CompletionText`='You return, $n.  Did you obtain the blood?', `VerifiedBuild`=36322 WHERE `ID`=26259; -- Blood of the Earthwarder

UPDATE `quest_request_items` SET `VerifiedBuild`=36322 WHERE `ID` IN (28824, 26507, 26440, 26437, 26768, 26766, 26427);

DELETE FROM `quest_request_items` WHERE `ID` IN (28404 /*I'll Do It By Hand*/, 28271 /*Reduced Productivity*/, 28352 /*Camel Tow*/, 28195 /*Sending a Message*/, 28193 /*Lockdown!*/, 27990 /*Battlezone*/, 28002 /*Crisis Management*/, 27969 /*Make Yourself Useful*/, 27926 /*Eastern Hospitality*/, 28480 /*Lieutenants of Darkness*/, 27779 /*Gnomebliteration*/, 27778 /*Hacking the Wibson*/, 27761 /*A Disarming Distraction*/, 27755 /*The Curse of the Tombs*/, 28501 /*The Defense of Nahom*/, 28499 /*Punish the Trespassers*/, 27900 /*I've Got This Guy*/, 28277 /*Salhet the Tactician*/, 28201 /*Ploughshares to Swords*/, 27838 /*The Root of the Corruption*/, 28611 /*The Defilers' Ritual*/, 27837 /*Trespassers in the Water*/, 27836 /*Stopping the Spread*/, 27519 /*Under the Choking Sands*/, 27520 /*Minions of Al'Akir*/, 28250 /*Thieving Little Pluckers*/, 27431 /*Tipping the Balance*/, 27511 /*The Thrill of Discovery*/, 28502 /*The Bandit Warlord*/, 28145 /*Venomblood Antidote*/, 28141 /*Relics of the Sun King*/, 28134 /*Impending Retribution*/, 27923 /*Smoke in Their Eyes*/, 27922 /*Traitors!*/, 28591 /*Off The Wall*/, 28589 /*Everything But the Kitchen Sink*/, 28586 /*Pool Pony Rescue*/, 28584 /*Quality Construction*/, 28588 /*Wildhammer Infestation*/, 27745 /*A Fiery Reunion*/, 27743 /*While We're Here*/, 27661 /*Fire the Cannon*/, 27703 /*Coup de Grace*/, 27701 /*Dragon, Unchained*/, 27662 /*Unbinding*/, 27659 /*Portal Overload*/, 27689 /*Distract Them for Me*/, 27655 /*Bring the Hammer Down*/, 27491 /*Kor'kron Drop*/, 27497 /*Call in the Artillery*/, 27493 /*Ogres & Ettins*/, 27863 /*The Crucible of Carnage: The Bloodeye Bruiser!*/, 28170 /*Night Terrors*/, 28151 /*Dressed to Kill*/, 28133 /*Fury Unbound*/, 28175 /*Shining Through the Dark*/, 28173 /*Blackout*/, 28191 /*A Fitting End*/, 28094 /*Paving the Way*/, 28091 /*Easy Pickings*/, 27509 /*Breach in the Defenses*/, 27507 /*Encroaching Twilight*/, 27506 /*Life from Death*/, 27505 /*Draconic Mending*/, 27300 /*Pushing Back*/, 27299 /*Torn Ground*/, 27955 /*Eye Spy*/, 27951 /*We All Must Sacrifice*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(28404, 0, 0, 0, 0, 'Almost got it...', 36372), -- I'll Do It By Hand
(28271, 0, 0, 0, 0, 'How\'d it go out there, $n?', 36372), -- Reduced Productivity
(28352, 0, 0, 0, 0, 'Were you able to tame some camels for me yet, $n?', 36372), -- Camel Tow
(28195, 0, 0, 0, 0, 'Haf my orders been carried out, $r?', 36372), -- Sending a Message
(28193, 0, 0, 0, 0, 'Vell, $r?$b$bVere zhe guests involved in zhe plot to haf me rubbed out?', 36372), -- Lockdown!
(27990, 0, 0, 0, 0, 'Vell?$b$bHas our little situation been brought under control?', 36372), -- Battlezone
(28002, 0, 0, 0, 0, 'Were you able to but the guests\' minds at ease, $r?', 36372), -- Crisis Management
(27969, 0, 0, 0, 0, 'Vhell, $r? Vere you... persvasive?', 36372), -- Make Yourself Useful
(27926, 0, 0, 0, 0, 'Well, hello again, $c.', 36372), -- Eastern Hospitality
(28480, 0, 0, 0, 0, 'You\'ve returned, $n.', 36372), -- Lieutenants of Darkness
(27779, 0, 0, 0, 0, 'The expedition members\' demise is unfortunate.', 36372), -- Gnomebliteration
(27778, 0, 0, 0, 0, 'Greetings, user $n.', 36372), -- Hacking the Wibson
(27761, 0, 0, 0, 0, 'Greetings, user $n.  I am happy to see you are still unaffected by the effects of the expedition curse.', 36372), -- A Disarming Distraction
(27755, 0, 0, 0, 0, 'Is it done, $n?  The expedition members cannot be saved.', 36372), -- The Curse of the Tombs
(28501, 0, 0, 0, 0, 'There is no time to waste!', 36372), -- The Defense of Nahom
(28499, 0, 1, 0, 0, 'You\'re back, $n.  Is your prowess as great as I\'ve heard?', 36372), -- Punish the Trespassers
(27900, 0, 0, 0, 0, 'This guy\'s tougher than he looks - and he looks tough!', 36372), -- I've Got This Guy
(28277, 0, 0, 0, 0, 'Did you see, $n?', 36372), -- Salhet the Tactician
(28201, 0, 0, 0, 0, 'You\'ve returned, $n.  How are the recruitment efforts faring?', 36372), -- Ploughshares to Swords
(27838, 0, 0, 0, 0, 'Is it done yet, $n.', 36372), -- The Root of the Corruption
(28611, 0, 0, 0, 0, 'Is it done, $n?', 36372), -- The Defilers' Ritual
(27837, 0, 0, 0, 0, 'You\'ve returned, $r.', 36372), -- Trespassers in the Water
(27836, 0, 0, 0, 0, 'Have you succeeded, $n?', 36372), -- Stopping the Spread
(27519, 0, 0, 0, 0, 'I thank you for your help, $n.', 36372), -- Under the Choking Sands
(27520, 0, 0, 0, 0, 'You\'re back!', 36372), -- Minions of Al'Akir
(28250, 0, 0, 0, 0, 'Did you do it, $n?', 36372), -- Thieving Little Pluckers
(27431, 0, 0, 0, 0, 'What have you found, $n?', 36372), -- Tipping the Balance
(27511, 0, 0, 0, 0, 'Find anything interesting, $n?', 36372), -- The Thrill of Discovery
(28502, 0, 0, 0, 0, 'You\'ve returned, $n.', 36372), -- The Bandit Warlord
(28145, 0, 0, 0, 0, 'Did you obtain it, $n?', 36372), -- Venomblood Antidote
(28141, 0, 0, 0, 0, 'Did you succeed?', 36372), -- Relics of the Sun King
(28134, 0, 0, 0, 0, 'You\'ve returned, $n.  Have you completed the task I request of you?', 36372), -- Impending Retribution
(27923, 0, 0, 0, 0, 'Is it done, $n?', 36372), -- Smoke in Their Eyes
(27922, 0, 0, 0, 0, 'What did you witness, $n?', 36372), -- Traitors!
(28591, 0, 0, 0, 0, 'It\'s a wonder they haven\'t hit the big collection of explosive gas above us yet. ', 36372), -- Off The Wall
(28589, 0, 15, 0, 0, 'Whatsa matter? You go blind? Can\'t you see we\'re still being creamed here?$B$BGet back on one of those cannons and pulverize those Wildhammer!', 36372), -- Everything But the Kitchen Sink
(28586, 0, 0, 0, 0, 'Maybe you\'d be willing to fly back down there and rescue a few more of our laborers?', 36372), -- Pool Pony Rescue
(28584, 0, 6, 0, 0, 'Look, I\'m just a simple cartographer, but according to my estimates, not to mention what my eyes are telling me, there are a few more faulty valves that need to be sealed.', 36372), -- Quality Construction
(28588, 0, 5, 0, 0, 'What? That\'s all you\'ve killed?$B$BGet back out there and take care of the rest!', 36372), -- Wildhammer Infestation
(27745, 5, 0, 0, 0, '$n!', 0), -- A Fiery Reunion
(27743, 0, 0, 0, 0, 'Let\'s take care of a few more of them, okay?', 36372), -- While We're Here
(27661, 0, 34, 0, 0, 'Lord Cannon\'s not dead. I\'d know if he were.', 36372), -- Fire the Cannon
(27703, 0, 6, 0, 0, 'That\'s all? I think that you can finish off a few more.', 36372), -- Coup de Grace
(27701, 0, 396, 0, 0, 'All you have to do is use the axe to break Lirastrasza\'s chains.', 36372), -- Dragon, Unchained
(27662, 0, 6, 0, 0, 'Try a few more, would ya?', 36372), -- Unbinding
(27659, 0, 1, 0, 0, 'We need those portals shutdown and their ascendant guardians slain, $c.', 36372), -- Portal Overload
(27689, 0, 274, 0, 0, 'They\'re not all dead yet now are they?', 36372), -- Distract Them for Me
(27655, 0, 396, 0, 0, 'Go back and kill more.', 36372), -- Bring the Hammer Down
(27491, 0, 25, 0, 0, 'I need you to get those Kor\'kon assassins safely to their destination, $n.', 36372), -- Kor'kron Drop
(27497, 0, 1, 0, 0, 'We need those buildings to be marked if our bombardment is to be effective.', 36372), -- Call in the Artillery
(27493, 0, 6, 0, 0, 'There are more to be killed, $r. You do have the stomach for that, yes?', 36372), -- Ogres & Ettins
(27863, 0, 1, 0, 0, 'No payout until the fight\'s over, $g man:lady;.', 36372), -- The Crucible of Carnage: The Bloodeye Bruiser!
(28170, 0, 274, 0, 0, 'Don\'t fear de darkness, mon.', 36372), -- Night Terrors
(28151, 0, 6, 0, 0, 'How is your disguise holding up? And what\'s happening with those ogres?', 36372), -- Dressed to Kill
(28133, 0, 1, 0, 0, 'Our dominance over the dragons is both our strength and our curse. Their wrath is a terrible thing to behold.', 36372), -- Fury Unbound
(28175, 0, 1, 0, 0, 'The black flight may never be redeemed, but in the wake of all of their destruction, there is always hope for life anew.', 36372), -- Shining Through the Dark
(28173, 0, 1, 0, 0, 'Trust me, I know how distasteful it sounds. We have a grim task ahead of us, but tenderness and sympathy must be put aside in these moments... for the sake of all life.', 36372), -- Blackout
(28191, 0, 0, 0, 0, 'There is more that must be done...', 36372), -- A Fitting End
(28094, 0, 0, 0, 0, 'Not done yet, bucko.', 36372), -- Paving the Way
(28091, 0, 1, 0, 0, 'There are still some guards left down there. Finish\'m off.', 36372), -- Easy Pickings
(27509, 0, 0, 0, 0, 'Did you find the breach?', 36372), -- Breach in the Defenses
(27507, 0, 1, 0, 0, 'It was inevitable I suppose. We\'ve kept them out for far longer than I thought we could. They were sure to find a way eventually.', 36372), -- Encroaching Twilight
(27506, 0, 6, 0, 0, 'Have you done as I asked?', 36372), -- Life from Death
(27505, 0, 25, 0, 0, 'Keep the menders safe as they heal our wounded dragons!', 36372), -- Draconic Mending
(27300, 0, 1, 0, 0, 'All over da highlands, da Twilight pervert da elements and turn dem against us. We\'ve witnessed unbearable horrors at dey\'re hands. I\'m eager to see dem slaughtered.', 36372), -- Pushing Back
(27299, 0, 6, 0, 0, 'Did ya have any luck with dose tentacles?', 36372), -- Torn Ground
(27955, 0, 6, 0, 0, 'What did the Eye show you?', 36372), -- Eye Spy
(27951, 0, 0, 0, 0, 'I have been watching you, $r.', 36372); -- We All Must Sacrifice

UPDATE `quest_request_items` SET `CompletionText`='Hail, $n!', `VerifiedBuild`=36372 WHERE `ID`=28486; -- Salhet's Gambit
UPDATE `quest_request_items` SET `CompletionText`='It is good to see you once more, $n.', `VerifiedBuild`=36372 WHERE `ID`=28483; -- Bleeding the Enemy
UPDATE `quest_request_items` SET `CompletionText`='Did you succeed, $n?  I estimated your chances of survival at 68.5%.', `VerifiedBuild`=36372 WHERE `ID`=27777; -- Core Access Codes
UPDATE `quest_request_items` SET `CompletionText`='Did you retrieve the codex, $n?', `VerifiedBuild`=36372 WHERE `ID`=28500; -- The Cypher of Keset
UPDATE `quest_request_items` SET `CompletionText`='Did you find them, $n?  Were they salvageable?', `VerifiedBuild`=36372 WHERE `ID`=28498; -- The Secret of Nahom
UPDATE `quest_request_items` SET `CompletionText`='You\'ve returned, $n.  How did the operation go?', `VerifiedBuild`=36372 WHERE `ID`=27839; -- Ancient Weapons
UPDATE `quest_request_items` SET `CompletionText`='You\'re back, $n!' WHERE `ID`=27706; -- The Scepter of Orsis
UPDATE `quest_request_items` SET `CompletionText`='Did you get the pieces, $n?', `VerifiedBuild`=36372 WHERE `ID`=27924; -- Budd's Plan
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=28595; -- Krazz Works!
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=28593; -- Of Utmost Importance
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=28583; -- Krazzworks
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=36372 WHERE `ID`=27742; -- A Little on the Side
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=36372 WHERE `ID`=27696; -- The Elementium Axe
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=36372 WHERE `ID`=27653; -- Dark Assassins
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=36372 WHERE `ID`=28166; -- Thog's Nightlight
UPDATE `quest_request_items` SET `EmoteOnComplete`=273, `EmoteOnIncomplete`=273, `CompletionText`='This is good, $n. With heroes like you stirring up trouble out here, we\'ll keep the cult distracted from our main invasion.$B$BDo you have a disguise?', `VerifiedBuild`=36372 WHERE `ID`=28147; -- Purple is Your Color
UPDATE `quest_request_items` SET `EmoteOnComplete`=274, `EmoteOnIncomplete`=274, `CompletionText`='Shhh, $n! Listen. Listen...', `VerifiedBuild`=36372 WHERE `ID`=28149; -- Whispers in the Wind
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=36372 WHERE `ID`=28123; -- The Demon Chain
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `VerifiedBuild`=36372 WHERE `ID`=28092; -- If The Key Fits
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=36372 WHERE `ID`=28090; -- Precious Goods
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=36372 WHERE `ID`=27508; -- Far from the Nest
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=36372 WHERE `ID`=27302; -- Simple Solutions
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=36372 WHERE `ID`=27945; -- Paint it Black
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID`=27750; -- War Forage
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=27751; -- Crushing the Wildhammer

UPDATE `quest_request_items` SET `VerifiedBuild`=36372 WHERE `ID` IN (28272, 28350, 28194, 27942, 27943, 27941, 27939, 27928, 27901, 28210, 27632, 28200, 27623, 27624, 27549, 27179, 28105, 27379, 28041);
