--
ALTER TABLE `page_text` MODIFY `VerifiedBuild` int(11) NOT NULL DEFAULT '0';

-- The Collector's Schedule (all three pages), source: vmangos
UPDATE `page_text` SET `Text`='Below is the process and schedule of Defias gold collection from the mines of Elwynn to our headquarters in Westfall.\n \nCollection Schedule:\n\nSunday: 12:30pm\nWednesday: 12:30pm\n\nBy each specified day, gold gained from the Elwynn mines will be gathered at the Brackwell pumpkin patch.  The agent in charge of these gatherings, \"The Collector,\" will be known by the engraved ring he possesses.  A ring I gave him.', `VerifiedBuild`=34713 WHERE `ID`=79;
UPDATE `page_text` SET `Text`='A party from Defias headquarters will contact the Collector, after which he will transfer the gathered gold.\n\nBe sure this process is performed without fail and with utmost discretion.  The Collector is responsible for the transfer of gold, but ultimately it is the responsibility of each member of the Defias Brotherhood to ensure that his role is acted out with attention and discipline.', `VerifiedBuild`=34713 WHERE `ID`=250;
UPDATE `page_text` SET `Text`='Remember, my brothers, we were once proud craftsmen.  We\'ll perform our current duties with the same precision we used in our past trade.\n\n-EVC', `VerifiedBuild`=34713 WHERE `ID`=251;

-- Defias Script
UPDATE `page_text` SET `Text`="The plan is set in motion.$B$BTake that once-great bastion of faith, Heroes' Vigil, as our base camp, and we'll begin to move reinforcements to you from Westfall once you have sent word that it has been suitably prepared.$B$BThe area is all but forgotten to the citizens and soldiers of Stormwind, and should prove a perfect staging point for our attacks.$B$BThe Defias will take back Stormwind!$B$BI await your response." WHERE `ID`=811;

-- Wiley's Note (both pages)
UPDATE `page_text` SET `Text`="Stoutmantle --$B$BSome nerve sending a total stranger to discuss the Defias gang.  Once you saved my life and now you put it in great peril.$B$BBut I owe you.  The Defias Brotherhood is larger than you think.  Every mine from Westfall to Elwynn Forest is under their control.  Kobolds and Gnolls have been enlisted to do their dirty work.  They have goblins crafting metal monsters to place in the Westfall fields to prey on the superstitions of the local residents." WHERE `ID`=38;
UPDATE `page_text` SET `Text`="They have a vast underground network built.  Bigger than you know, Stoutmantle.  From Booty Bay right to Stormwind Keep.  You may be a brave Paladin but you are a fool if you think you can shut them down.  They are working on a weapon of mass destruction.  After all, if there's one thing Stonemasons know, it's how to build big.  You didn't think this was about pumpkin farms and vineyards, now did you?  I repaid your favor.  Now leave me be!$B$B--W" WHERE `ID`=39;

-- Shaw's Report (first page only)
UPDATE `page_text` SET `Text`="Lord Stoutmantle--$B$BLed by Edwin VanCleef, the Stonemason's Guild was composed of the most skilled builders among men.  The Stonemasons helped to rebuild the broken city of Stormwind that was razed by the orcs during the First War. VanCleef and his tradesmen were peerless builders and their work and artistry was evident in the edifices of the Cathedral of Light and Stormwind Keep itself." WHERE `ID`=41;

-- A Mysterious Message
UPDATE `page_text` SET `Text`="Blacknails--$B$BThe Sea awaits us.  We need your supplies from the North.  Strip everything: every railroad pike, every waterbucket.  We need metal.  A shipment is due from BB but long overdue.  Come through for me, Blacknails.  Send your supplies directly to the \"barn\" this time.  No time to squander.$B$B--VanCleef" WHERE `ID`=48;

-- Solomon's Plea to Westfall
UPDATE `page_text` SET `Text`="Lord Stoutmantle --$B$BThe Township of Lakeshire humbly requests the aid of your Militia.  As I write this, we find ourselves under siege from both the Blackrock Orcs and Morganth's Shadowhide Gnolls.  I would not send bidding if our situation was not severe.  We await aid from Stormwind but until such help arrives, I beg of you to lend support.  Once the Kingdom is breeched, all of Humanity is in peril.$B$BMagistrate Solomon" WHERE `ID`=49;

-- Stoutmantle's Response to Solomon
UPDATE `page_text` SET `Text`="Your Honor--$B$BAll of Westfall mourns for your loss,  but we are plagued with our own war in Westfall.  The farmers have been run off by thieves and mechanical golems.  Stormwind withdrew its troops, leaving the people defenseless.  I mustered the People's Militia in the wake of Stormwind's abandonment to save what remains of this land.  To take the Militia to Redridge would mean certain doom for Westfall.$B$BMy regrets,$BGryan Stoutmantle" WHERE `ID`=50;

-- Solomon's Plea to Darkshire
UPDATE `page_text` SET `Text`="Lord Ebonlocke--$B$BThe Township of Lakeshire humbly requests the aid of the Night Watch.  We are under siege from both the Blackrock orcs and Morganth's Shadowhide gnolls.  I would not send bidding if our situation was not severe.  We await aid from Stormwind but until such help arrives, I beg of you to lend support.  Once the kingdom is breached, all of humanity is in peril.$B$BMagistrate Solomon" WHERE `ID`=51;

-- Ebonlocke's Response to Solomon
UPDATE `page_text` SET `Text`="Your Honor--$B$BI regret to inform you that the Night Watch is unable to leave its post in Darkshire at this time.  Perhaps you were unaware that Stormwind no longer provides military support in this region.  The Night Watch has been formed and trained entirely by the people of the forest in order to defend Darkshire in Stormwind's absence.  Without the Watch, the town would fall.  I wish you luck with your plight.$B$B--Lord Ello Ebonlocke" WHERE `ID`=52;
