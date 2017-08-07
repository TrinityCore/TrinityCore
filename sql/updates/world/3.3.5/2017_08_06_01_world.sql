-- Invaluable Asset Zapping (10203): add missing last third of RewardText
UPDATE `quest_offer_reward`
 SET `RewardText`="You must be the one that zapped all of that sapping equipment back to us here from the ruins! Hooray for you!$B$BI've already reallocated the equipment out to our other locations. Now we'll be able to expedite our fissure operations on this whole island by an order of magnitude! The nether-rocket will be completed in no time!$B$BHmmm, that's odd. Wait a minute, did you say that you sent four things back to us? I only got three..."
 WHERE `Id`=10203;
