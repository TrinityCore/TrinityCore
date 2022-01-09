-- Test of Endurance (1150) / replace "troll" with $r
UPDATE `quest_offer_reward` SET `RewardText`="Grenka was powerful, even by $r standards. You should be proud of your accomplishment this day.$b$bDuring your test of faith you displayed strength of spirit, and now you have shown endurance in battle by taking on the Roguefeather harpies, but the time has come for a new test." WHERE `ID`=1150;
