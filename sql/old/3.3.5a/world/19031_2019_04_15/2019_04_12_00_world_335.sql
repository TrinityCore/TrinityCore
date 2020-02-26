-- 
UPDATE `quest_greeting` SET `Greeting`="Well, hello there. You seem like you wouldn't be opposed to making some coin, hm? I can tell from the look in your eyes. I am Mogul Kebok, overseer of operations in Azeroth, and if it is riches you seek, perhaps I can make arrangements." WHERE `ID`=737;
UPDATE `quest_greeting` SET `Greeting`="$C, eh? I am Krazek, Baron Revilgaz's secretary. I know everything about the goings on in this jungle and beyond. Perhaps you'd be interested in knowing the going price on oil in Ratchet? No? Looking for work, maybe? I can help you there." WHERE `ID`=773;
UPDATE `quest_greeting` SET `Greeting`="This cauldron churns with thick, green bubbles.  Skulls, bones and organs of unknown creatures swim within its viscous broth...$B$BAnd rising lazily to the surface are the skulls of two, once mighty trolls:$B$BGan'zulah and Nezzliok." WHERE `ID`=2076;
UPDATE `quest_greeting` SET `Greeting`="Information... With our scouts and agents, we control the flow of information in Lordaeron. Scourge movements, their holdings, all underneath our watchful eyes..." WHERE `ID`=2121;
UPDATE `quest_greeting` SET `Greeting`="How perfect of you to come by, $c.$B$BMy name is Lotwil Veriatus, founding member of the Enlightened Assembly of Arcanology, Alchemy, and Engineering Sciences: we seek to blend the intelligent sciences of Azeroth together into one comprehensive school." WHERE `ID`=2921;
UPDATE `quest_greeting` SET `Greeting`="Don't let the heat bother you.  In the Badlands, heat is the least of your worries." WHERE `ID`=5394;
UPDATE `quest_greeting` SET `Greeting`="This sty's a little shy of comfy, but it has history, so Stonard must be important to someone. I'd gamble that's why we stay here. It sure ain't for the view--it don't even look like home." WHERE `ID`=5591;
UPDATE `quest_greeting` SET `Greeting`="Hello, $N. Perhaps you have some time to chat?" WHERE `ID`=7900;
UPDATE `quest_greeting` SET `Greeting`="Dear $g boy:girl;, you have arrived just in time to assist the Kargath Expeditionary Force." WHERE `ID`=9078;
UPDATE `quest_greeting` SET `Greeting`="Greetings, $N. I am Duke Nicholas Zverenhoff of the Argent Dawn." WHERE `ID`=11039;
UPDATE `quest_greeting` SET `Greeting`="Curse that Brewers' League! They have access to all the best ingredients, while we're stuck here grubbing for grain and hops!$B$BI really would like to give them some bitter tasting justice..." WHERE `ID`=1374; -- Rejold Barleybrew

DELETE FROM `quest_greeting` WHERE `ID` IN (5770,273,1071,2700,2713,2276,2263,186420,265,4794,7884,10306,23572);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(5770,0,0,0,"If we are to protect nature, then we must embrace its strength.  And we must show this strength to those who would harm the land.",0), -- Nara Wildmane
(273,0,0,0,"Keep the door closed, $c. Never know when the Dark Riders will be passing through again.",0), -- Tavernkeep Smitts
(1071,0,0,0,"If there's one thing that Rhag taught me it's that no assignment is a dull one. Protecting the Thandol Span should have been an easy task. But with the brunt of the army fighting alongside the Alliance, we were overwhelmed here and Dun Modr has fallen.",0), -- Longbraid the Grim
(2713,1,0,0,"This wooden board holds roughly made wanted posters.",0), -- Wanted Board
(2700,0,0,0,"We at Refuge Pointe hold one of the few remaining patches of Stromgarde territory in the Arathi Highlands. And we're losing ground...$B$BIf you have words for me, then I hope they are good doings.",0), -- Captain Nials
(2276,0,0,0,"When I was first offered the title of Southshore Magistrate I was exalted to have earned such a commission so early in my career.$B$BBut now that I'm here, I wonder if I'd have been better off shuffling papers in Stormwind.",0), -- Magistrate Henry Maleb
(2263,0,0,0,"I hope you're here to work, $C. We have a lot to do and the Horde, the Syndicate and the Ogres aren't going to help us.",0), -- Marshal Redpath
(186420,1,0,0,"This collection of scrolls contains various logistic and strategic information, as well as coded correspondences.",0), -- Syndicate Documents
(265,0,0,0,"I have sensed your coming for quite some time, $n.  It was written in the pattern of the stars.",0), -- Madame Eva
(4794,0,0,0,"Researching in Theramore is an interesting job, but it's sure hard to find a soft bed in this town!",0), -- Morgan Stern
(7884,0,0,0,"",0), -- Fraggar Thundermantle
(10306,0,0,0,"",0), -- Trull Failbane
(23572,0,0,0,"",0); -- Drazzit Dripvalve
