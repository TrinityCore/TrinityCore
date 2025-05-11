DELETE FROM `quest_offer_reward` WHERE `ID` IN (27091 /*Charge!*/, 8329 /*Warrior Training*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(27091, 1, 0, 0, 0, 0, 0, 0, 0, 'I think you\'ve mastered the basics of the charge, $N. Don\'t forget to return when you need more training.', 58558), -- Charge!
(8329, 1, 1, 0, 0, 0, 0, 0, 0, 'Welcome to the Sunspire, young warrior!  Mastery of weapons and battle tactics begins here and now - all I ask of my pupils is that they cover payment for training costs that may come up, and that they are as good of a listener as they are an aspiring warrior.  The lessons I have to teach are extensive, and I don\'t like to repeat myself unnecessarially.$B$BLet\'s get to it then! ', 58558); -- Warrior Training

UPDATE `quest_offer_reward` SET `RewardText`='Felendren\'s head... you are to be commended, $N.  You\'ve succeeded where others, like Felendren, have utterly failed.  Perhaps you are truly ready to be a contributing member of blood elf society.$B$BYour success here means that you are capable of surviving the greater threats that lurk in Eversong... and believe me, there are plenty to face.', `VerifiedBuild`=58558 WHERE `ID`=8335; -- Felendren the Banished
UPDATE `quest_offer_reward` SET `RewardText`='This is... most interesting.  And when I say interesting, I mean more disturbing than anything else.$B$BOur efforts to reassert control over the isle in the time following the destruction of the Sunwell have been a challenge.  I suspect that whatever foul source is corrupting the isle is at the heart of it all; this sliver may be of some aid in uncovering what\'s really going on.$B$BYou were wise to bring this to me, $N.  Take this as compensation for your diligence.  Thank you.', `VerifiedBuild`=58558 WHERE `ID`=8338; -- Tainted Arcane Sliver
UPDATE `quest_offer_reward` SET `RewardText`='Magistrix Erona told me you\'d be along quick enough, $N.  The Falthrien Academy to our west - the huge floating building with the ornate spires - is in bad shape.  You\'re going to be leading the effort to recapture it from one of the Wretched - a blood elf who has forever succumbed to their basest cravings.$B$BI hope you\'re ready to work.  This is not only going to be a lesson about danger, but also of what happens when you forsake the realities of who you are.', `VerifiedBuild`=58558 WHERE `ID`=8327; -- Report to Lanthan Perilon
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You are a quick study, $N. I look forward to the opportunity to teach you again in the future.', `VerifiedBuild`=58558 WHERE `ID`=10068; -- Arcane Missiles
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `RewardText`='Ah, $N - I believe you\'re one of the new mages here on the isle, yes?  Well, you\'ve come to the right place.  If arcane mastery is what you seek, then I can provide such knowledge - as long as you have the wherewithal to handle training costs and the capacity to focus on the lessons I\'ll be teaching.$B$BLet\'s get started! ', `VerifiedBuild`=58558 WHERE `ID`=8328; -- Mage Training
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=58558 WHERE `ID`=8483; -- The Dwarven Spy
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=58558 WHERE `ID`=8482; -- Incriminating Documents
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='My endeavors are hopeless, $N.  The very nature of the soil has been altered... the taint is irreversible.  Thank you for your assistance.  I\'ll need to ask one last task of you.', `VerifiedBuild`=58558 WHERE `ID`=8488; -- Unexpected Results
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Excellent.  I will cast an augmentation enchantment on the samples so I can more clearly analyze the taint on the soil.', `VerifiedBuild`=58558 WHERE `ID`=8487; -- Corrupted Soil
UPDATE `quest_offer_reward` SET `RewardText`='It\'s so nice of my old mentor to check on me.  It\'s too bad she lost faith in my research long ago.$B$BDon\'t waste your time trying to get me to return to her; you can either help me with my research or leave.', `VerifiedBuild`=58558 WHERE `ID`=9254; -- The Wayward Apprentice
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=500, `EmoteDelay3`=500, `VerifiedBuild`=58558 WHERE `ID`=8886; -- Grimscale Pirates!
UPDATE `quest_offer_reward` SET `EmoteDelay2`=500, `RewardText`='At last! Though the Grimscale did not route, as hoped, it was entertaining to watch them panic in confusion when you laid low their so-called chieftain. You have my thanks, and the gratitude of the sin\'dorei of Silvermoon City!$B$BPlease, take one of these in thanks for the service that you have rendered.', `VerifiedBuild`=58558 WHERE `ID`=8885; -- The Ring of Mmmrrrggglll
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=58558 WHERE `ID`=8480; -- Lost Armaments
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=58558 WHERE `ID`=8887; -- Captain Kelisendra's Lost Rutters
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6, `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=58558 WHERE `ID`=9395; -- Saltheril's Haven
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=58558 WHERE `ID`=9135; -- Return to Sathiel
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=58558 WHERE `ID`=9134; -- Skymistress Gloaming
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `EmoteDelay2`=1000, `VerifiedBuild`=58558 WHERE `ID`=9133; -- Fly to Silvermoon City
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=58558 WHERE `ID`=9130; -- Goods from Silvermoon City
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=500, `RewardText`='A job well done, $c.  By the smell of it, I\'d say you returned all that I asked for, and possibly more.  I\'m sure we can find some use for these, in a stew, or somesuch.$B$BAlas, it does not appear that your efforts have done the trick; the murlocs are not in retreat.  This calls for more direct action!', `VerifiedBuild`=58558 WHERE `ID`=8884; -- Fish Heads, Fish Heads...
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=58558 WHERE `ID`=8486; -- Arcane Instability
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You\'ve done as I\'ve asked, $n, and you may take your reward now.', `VerifiedBuild`=58558 WHERE `ID`=9404; -- Recently Living
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1, `RewardText`='Let\'s see what you\'ve brought me...$b$b<He holds the phial up to the light and examines it closely.>$b$bYes, this will do.  Well done, $n.', `VerifiedBuild`=58558 WHERE `ID`=9403; -- The Purest Water
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `RewardText`='Oh, well done...  I told you to jump in a pond, and you did.  I can only imagine what you\'d do if one of your good friends asked it of you.$b$bIf you want a reward for your efforts, it is this: never lift a finger without first knowing what\'s in it for you.  The mage\'s mind is $ghis:her; greatest weapon.  Remember that and try to use yours a bit more.', `VerifiedBuild`=58558 WHERE `ID`=9402; -- Fetch!
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N. You are quickly becoming one of my best students and I look forward to continuing your training in the future.', `VerifiedBuild`=58558 WHERE `ID`=10073; -- Immolation
UPDATE `quest_offer_reward` SET `RewardText`='$N - your name has passed my ears as one seeking out a master in the ways of the warlock.  You look capable enough, but I seek more than just looks from my students.  You must be ready to delve where others fear to look to gain your power.  I will teach you, but I will not tolerate failure.$B$BThere will be monetary costs associated with your training, but you should be more concerned with the cost your mind is willing to make.  If you are ready, we shall begin.', `VerifiedBuild`=58558 WHERE `ID`=8563; -- Warlock Training
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=58558 WHERE `ID`=10072; -- Healing the Wounded
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=58558 WHERE `ID`=8564; -- Priest Training
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You\'ve mastered this lesson in a short time, $N. That bodes well for your future as a rogue. Return to me when you are ready to continue your training.', `VerifiedBuild`=58558 WHERE `ID`=10071; -- Evisceration
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You have done well, $N. You should be proud of your progress. Seek me out when you need further training.', `VerifiedBuild`=58558 WHERE `ID`=10070; -- Steady Shot
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`='$N, are your eyes keen as a hawk\'s, your motions as fluid as a monkey\'s, or your speed that of a cheetah?  Mine are, and yours can be too with the proper training.  The way of the hunter is one of mastery over the beasts of the world, an unparalleled precision in marksmanship, and the knowledge of how to survive in situations where others would perish.$B$BIf these are the things that you seek to learn, then I will train you - for a small fee, of course.  Shall we begin?', `VerifiedBuild`=58558 WHERE `ID`=9393; -- Hunter Training
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=58558 WHERE `ID`=10069; -- Ways of the Light
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=58558 WHERE `ID`=9676; -- Paladin Training
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=58558 WHERE `ID`=8490; -- Powering our Defenses
UPDATE `quest_offer_reward` SET `RewardText`='You must\'ve been sent by someone at Fairbreeze Village.  I knew it would just be a matter of time until help arrived.', `VerifiedBuild`=58558 WHERE `ID`=9253; -- Runewarden Deryan
UPDATE `quest_offer_reward` SET `RewardText`='I no longer belong to this world and must admit defeat.  The land has forever changed and nothing will ever be the same.$B$BLeave the pendant here with me, $N.  Maybe one day, long after the elves are gone, a new tree will grow on this very spot - amongst a burnt forest and the husks of dead treants.', `VerifiedBuild`=58558 WHERE `ID`=10166; -- Whitebark's Memory
UPDATE `quest_offer_reward` SET `Emote1`=5, `RewardText`='So, it is done.  Curse these times that have driven us to desperate measures... and curse our enemy, the Scourge!$B$BLearn this, $N.  Our lands must be protected, no matter what the cost.  We shall prevail!', `VerifiedBuild`=58558 WHERE `ID`=8473; -- A Somber Task
UPDATE `quest_offer_reward` SET `Emote1`=18, `EmoteDelay1`=500, `VerifiedBuild`=58558 WHERE `ID`=8474; -- Old Whitebark's Pendant
UPDATE `quest_offer_reward` SET `RewardText`='Ah, my brother sent you.  I do have a task I could use assistance with.', `VerifiedBuild`=58558 WHERE `ID`=9258; -- The Scorched Grove
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `RewardText`='You\'re quite the energetic young $g man : woman;, aren\'t you?$B$BThis all looks very adequate.  You certainly deserve compensation for gathering up all of this for me, and something a little extra I think.$B$BOh, I almost forgot, here\'s an invitation to the party.  And, $c, next time that you drop in make sure to dress up in something a little more... festive.', `VerifiedBuild`=58558 WHERE `ID`=9067; -- The Party Never Ends
UPDATE `quest_offer_reward` SET `RewardText`='These notes... are shocking.  If they\'re correct it means the damage to the land on the Dead Scar is irreversible.$B$BI\'ll notify the grand magister right away.  More reason for our race to escape this world and find our true fate in Outland.', `VerifiedBuild`=58558 WHERE `ID`=9255; -- Research Notes
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=500, `EmoteDelay3`=500, `RewardText`='Here it is, $N, the proof of my crime. This journal contains all of my ill-conceived studies.$B$BHeedless of the warnings, I continued my research until it was almost too late. Then, when I grasped my error, I did what I could. But by then, some of my pupils had already gone too far. I evacuated the Spire to get them away from the corruption, but in my haste, forgot to shut down the power sources.$B$BI will burn this tome so that no one else falls prey to its contents. I only wanted to help the sin\'dorei.', `VerifiedBuild`=58558 WHERE `ID`=8891; -- Abandoned Investigations
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=18, `EmoteDelay2`=500, `RewardText`='No! I was too late. It is all my fault.$B$BMy investigation into purifying alternative magical sources got out of hand before I could put a stop to it. If only I had gone myself... or that they had listened to me, and heeded my warnings!$B$BI have blood on my hands, $c. I thank you, though, for putting to rest the tortured souls of my former apprentices. It is some small consolation that they will not linger in that state where a blood elf is better off dead.', `VerifiedBuild`=58558 WHERE `ID`=8890; -- Word from the Spire
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=500, `VerifiedBuild`=58558 WHERE `ID`=8889; -- Deactivating the Spire
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=500, `RewardText`='Well, I suppose that will have to do, now won\'t it? Thanks for the help, $c. I can only hope to get this mess completely cleaned up before the Magister returns to Duskwither Spire.$B$BTake this pocket change; it\'s not much but it\'s all that I have at the moment. Feel free to dispatch a few more of the beasties on your way out, if you\'d be so kind.', `VerifiedBuild`=58558 WHERE `ID`=8894; -- Cleaning up the Grounds
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `EmoteDelay2`=1000, `RewardText`='Who are you?  You\'re not one of the magister\'s apprentices, that\'s for certain!$B$BSent here to help me clean up this mess, no doubt!', `VerifiedBuild`=58558 WHERE `ID`=9394; -- Where's Wyllithen?
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `EmoteDelay2`=500, `RewardText`='The magister was concerned for my wellbeing? How sweet; I wish that he had shown such an interest before, when we were at the Spire.$B$BThat doesn\'t matter now. Please listen carefully, $c, as I have a favor to ask of you.', `VerifiedBuild`=58558 WHERE `ID`=8888; -- The Magister's Apprentice
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='There\'s truth to the rumors, $N.  This hammer is light and strong at once; I shall manage to complete several of my unfinished projects.  And of course, I\'ll let you have first pick.', `VerifiedBuild`=58558 WHERE `ID`=8477; -- The Spearcrafter's Hammer
UPDATE `quest_offer_reward` SET `RewardText`='The trolls have been keeping us pinned here while planning an attack on Fairbreeze Village.  We were not expecting this at all.', `VerifiedBuild`=58558 WHERE `ID`=9360; -- Amani Invasion
UPDATE `quest_offer_reward` SET `RewardText`='Good work, $N.  With more people like you we\'ll soon restore our lands to their former glory.', `VerifiedBuild`=58558 WHERE `ID`=8476; -- Amani Encroachment
UPDATE `quest_offer_reward` SET `RewardText`='Ya, mon.  Zul\'Marosh had this comin\'.  He burn down Ven\'jashi\'s village.  I kill many Amani before they put me in this cage.  I hide something in the sand, my gift for you now.$B$BAh... ah, the poison... it spread now, mon.  Time to rest...', `VerifiedBuild`=58558 WHERE `ID`=8479; -- Zul'Marosh
UPDATE `quest_offer_reward` SET `RewardText`='You\'re here to help?  Excellent!$B$BThe battle against the Amani trolls has taken its toll on us and capable fighters such as yourself are always welcome.', `VerifiedBuild`=58558 WHERE `ID`=9359; -- Farstrider Retreat

DELETE FROM `quest_details` WHERE `ID` IN (8885 /*The Ring of Mmmrrrggglll*/, 8887 /*Captain Kelisendra's Lost Rutters*/, 8884 /*Fish Heads, Fish Heads...*/, 9035 /*Roadside Ambush*/, 10072 /*Healing the Wounded*/, 8564 /*Priest Training*/, 10070 /*Steady Shot*/, 9393 /*Hunter Training*/, 10069 /*Ways of the Light*/, 9676 /*Paladin Training*/, 27091 /*Charge!*/, 8329 /*Warrior Training*/, 10166 /*Whitebark's Memory*/, 8474 /*Old Whitebark's Pendant*/, 28560 /*Warchief's Command: Ghostlands!*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8885, 1, 1, 1, 0, 0, 500, 500, 0, 58558), -- The Ring of Mmmrrrggglll
(8887, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Captain Kelisendra's Lost Rutters
(8884, 1, 1, 5, 0, 0, 500, 500, 0, 58558), -- Fish Heads, Fish Heads...
(9035, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Roadside Ambush
(10072, 1, 1, 0, 0, 0, 1000, 0, 0, 58558), -- Healing the Wounded
(8564, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Priest Training
(10070, 1, 1, 0, 0, 0, 1000, 0, 0, 58558), -- Steady Shot
(9393, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Hunter Training
(10069, 1, 1, 0, 0, 0, 1000, 0, 0, 58558), -- Ways of the Light
(9676, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Paladin Training
(27091, 1, 1, 0, 0, 0, 1000, 0, 0, 58558), -- Charge!
(8329, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Warrior Training
(10166, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Whitebark's Memory
(8474, 6, 0, 0, 0, 0, 0, 0, 0, 58558), -- Old Whitebark's Pendant
(28560, 1, 1, 1, 0, 0, 0, 0, 0, 58558); -- Warchief's Command: Ghostlands!

DELETE FROM `quest_request_items` WHERE `ID`=27091;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(27091, 0, 0, 0, 0, 'Have you practiced your charge?', 58558); -- Charge!

UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='It is not an option or a choice... you must quench your magical thirst.  To fail in this is to fail as a blood elf.  Those who thought they could control their needs without tutoring now find themselves as one of the Wretched.$B$BYou do NOT want to end up as an insane addict.  Believe me.', `VerifiedBuild`=58558 WHERE `ID`=8346; -- Thirst Unending
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=58558 WHERE `ID`=8336; -- A Fistful of Slivers
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='It is better you learn about survival - and the costs of survival - now rather than later.  Making hard choices is something you\'re going to have to get used to as a blood elf.$B$BNo one was there for us when the Scourge ripped our home in two.  It was us and us alone who pulled ourselves up by the bootstraps.', `VerifiedBuild`=58558 WHERE `ID`=8334; -- Aggression
UPDATE `quest_request_items` SET `CompletionText`='Our work in rebuilding our society begins here, $N.  Once we are able to secure our home, we can look outward and upward.', `VerifiedBuild`=58558 WHERE `ID`=8325; -- Reclaiming Sunstrider Isle
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=58558 WHERE `ID`=9252; -- Defending Fairbreeze Village
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=58558 WHERE `ID`=8892; -- Situation at Sunsail Anchorage
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=8887;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='You are the instrument of my success and revenge, $c. Have you the ring?' WHERE `ID`=8885; -- The Ring of Mmmrrrggglll
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='We rangers of the Farstrider Retreat are dedicated to setting right the damage that has been wreaked upon our fair lands.  We will go to any length to do so.$B$BI trust that you have returned with the murloc heads I tasked you to gather?', `VerifiedBuild`=58558 WHERE `ID`=8884; -- Fish Heads, Fish Heads...
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=58558 WHERE `ID`=8486; -- Arcane Instability
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=66, `CompletionText`='You\'re back, $N.  Did you fight off the undead along the Dead Scar yet?', `VerifiedBuild`=58558 WHERE `ID`=8475; -- The Dead Scar
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=58558 WHERE `ID`=9252; -- Defending Fairbreeze Village
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=58558 WHERE `ID`=9404; -- Recently Living
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=58558 WHERE `ID`=9403; -- The Purest Water
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID` IN (10166, 8474);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=58558 WHERE `ID`=8336; -- A Fistful of Slivers
UPDATE `quest_request_items` SET `CompletionText`='Our work in rebuilding our society begins here, $N.  Once we are able to secure our home, we can look outward and upward.', `VerifiedBuild`=58558 WHERE `ID`=8325; -- Reclaiming Sunstrider Isle
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=58558 WHERE `ID`=8892; -- Situation at Sunsail Anchorage
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you mastered your new skill?', `VerifiedBuild`=58558 WHERE `ID`=10071; -- Evisceration
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you mastered using Steady Shot?', `VerifiedBuild`=58558 WHERE `ID`=10070; -- Steady Shot
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=8887;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you practiced using your new skills?', `VerifiedBuild`=58558 WHERE `ID`=10069; -- Ways of the Light
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='You are the instrument of my success and revenge, $c. Have you the ring?' WHERE `ID`=8885; -- The Ring of Mmmrrrggglll
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='We rangers of the Farstrider Retreat are dedicated to setting right the damage that has been wreaked upon our fair lands.  We will go to any length to do so.$B$BI trust that you have returned with the murloc heads I tasked you to gather?', `VerifiedBuild`=58558 WHERE `ID`=8884; -- Fish Heads, Fish Heads...
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=58558 WHERE `ID`=8486; -- Arcane Instability
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='You\'ll find Tor\'Watha and Zeb\'Watha southeast of here.  Come back when you\'ve killed the trolls.', `VerifiedBuild`=58558 WHERE `ID`=8476; -- Amani Encroachment
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=66, `CompletionText`='You\'re back, $N.  Did you fight off the undead along the Dead Scar yet?', `VerifiedBuild`=58558 WHERE `ID`=8475; -- The Dead Scar
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=58558 WHERE `ID`=8473; -- A Somber Task

DELETE FROM `creature_queststarter` WHERE (`id`=15283 AND `quest`=10073) OR (`id`=15278 AND `quest` IN (8563,8564,9393,9676,8329)) OR (`id`=15284 AND `quest`=10072) OR (`id`=15513 AND `quest`=10070) OR (`id`=15280 AND `quest`=10069) OR (`id`=43010 AND `quest`=27091);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(15283, 10073, 58558), -- Immolation offered by Summoner Teli'Larien
(15278, 8563, 58558), -- Warlock Training offered by Magistrix Erona
(15284, 10072, 58558), -- Healing the Wounded offered by Matron Arena
(15278, 8564, 58558), -- Priest Training offered by Magistrix Erona
(15513, 10070, 58558), -- Steady Shot offered by Ranger Sallina
(15278, 9393, 58558), -- Hunter Training offered by Magistrix Erona
(15280, 10069, 58558), -- Ways of the Light offered by Jesthenis Sunstriker
(15278, 9676, 58558), -- Paladin Training offered by Magistrix Erona
(43010, 27091, 58558), -- Charge! offered by Delios Silverblade
(15278, 8329, 58558); -- Warrior Training offered by Magistrix Erona

DELETE FROM `creature_questender` WHERE `id`=15279 AND `quest` IN (10068,8328) OR (`id`=15283 AND `quest` IN (10073,8563)) OR (`id`=15284 AND `quest` IN (10072,8564)) OR (`id`=15285 AND `quest`=10071) OR (`id`=15513 AND `quest` IN (10070,9393)) OR (`id`=15280 AND `quest` IN (10069,9676)) OR (`id`=43010 AND `quest` IN (27091,8329));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(15279, 10068, 58558), -- Arcane Missiles ended by Julia Sunstriker
(15279, 8328, 58558), -- Mage Training ended by Julia Sunstriker
(15283, 10073, 58558), -- Immolation ended by Summoner Teli'Larien
(15283, 8563, 58558), -- Warlock Training ended by Summoner Teli'Larien
(15284, 10072, 58558), -- Healing the Wounded ended by Matron Arena
(15284, 8564, 58558), -- Priest Training ended by Matron Arena
(15285, 10071, 58558), -- Evisceration ended by Pathstalker Avokor
(15513, 10070, 58558), -- Steady Shot ended by Ranger Sallina
(15513, 9393, 58558), -- Hunter Training ended by Ranger Sallina
(15280, 10069, 58558), -- Ways of the Light ended by Jesthenis Sunstriker
(15280, 9676, 58558), -- Paladin Training ended by Jesthenis Sunstriker
(43010, 27091, 58558), -- Charge! ended by Delios Silverblade
(43010, 8329, 58558); -- Warrior Training ended by Delios Silverblade
