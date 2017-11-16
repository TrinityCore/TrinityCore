-- 
DELETE FROM `quest_offer_reward` WHERE `ID` IN (29799, 29800, 30987, 30988, 30989, 31450);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(29799, 1, 0, 0, 0, 0, 0, 0, 0, 'You are a sight to see when under pressure, $n! We wouldn''t have stood a chance without you.$B$BI think it''s working. The flow of blood is slowing. I knew it would work!', 19831), -- 29799
(29800, 1, 0, 0, 0, 0, 0, 0, 0, 'It is good to see you again, $n. You''ve done all that I''ve asked of you and more... you have saved Shen-zin Su.$B$BYou make an old master proud.', 19831), -- 29800
(30987, 273, 0, 0, 0, 0, 0, 0, 0, 'Pandaren... you''re here.$b$bGood.', 19831), -- 30987
(30988, 0, 0, 0, 0, 0, 0, 0, 0, 'Before you go, $n - I have one more thing to discuss with you.', 19831), -- 30988
(30989, 0, 0, 0, 0, 0, 0, 0, 0, 'You''ve more than proven your worth, in battle and in heart. Few would be willing to leave their homeland to join the Alliance. Fewer still would be willing to face the King of Stormwind in combat.$b$bYou, and the rest of your people, are welcome among our ranks. Welcome to the Alliance, $n.', 19831), -- 30989
(31450, 1, 0, 0, 0, 0, 0, 0, 0, 'And so it is done... here we are, in our new home.', 19831); -- 31450

DELETE FROM `quest_details` WHERE `ID` IN (29800, 30987, 30988, 30989, 31450);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(29800, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29800
(30987, 0, 0, 0, 0, 0, 0, 0, 0, 19831), -- 30987
(30988, 0, 0, 0, 0, 0, 0, 0, 0, 19831), -- 30988
(30989, 0, 0, 0, 0, 0, 0, 0, 0, 19831), -- 30989
(31450, 396, 0, 0, 0, 0, 0, 0, 0, 19831); -- 31450

DELETE FROM `quest_offer_reward` WHERE `ID` IN (29665, 29779, 29780, 29781, 29782, 29784, 29785, 29786, 29787, 29788, 29789, 29790, 29791, 29792, 29793, 29794, 29795, 29796, 29797, 29798, 30589, 30590, 30591, 30767);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(29665, 1, 0, 0, 0, 0, 0, 0, 0, 'You are a fear to behold upon the battlefield.', 19831), -- 29665
(29779, 1, 0, 0, 0, 0, 0, 0, 0, 'Invigorating! A good fight always makes me feel better!', 19831), -- 29779
(29780, 1, 0, 0, 0, 0, 0, 0, 0, '$n, I think you''ve got a bit of Huojin in you. Stick with me and I''ll bring you around, I think.', 19831), -- 29780
(29781, 1, 0, 0, 0, 0, 0, 0, 0, '$n, I''m thinking we should celebrate with these later. What do you think?', 19831), -- 29781
(29782, 1, 0, 0, 0, 0, 0, 0, 0, 'GOOD! A true challenge. Let us put this pillar to the test!', 19831), -- 29782
(29784, 1, 0, 0, 0, 0, 0, 0, 0, 'I''m impressed. Most students that are even capable of reaching this spot do so soaking wet.', 19831), -- 29784
(29785, 1, 0, 0, 0, 0, 0, 0, 0, 'Dafeng looks frightened as you approach, but settles a bit at the sound of your voice.', 19831), -- 29785
(29786, 1, 0, 0, 0, 0, 0, 0, 0, 'You have helped Dafeng, the spirit of air, find his courage! The final spirit has been restored.', 19831), -- 29786
(29787, 1, 0, 0, 0, 0, 0, 0, 0, 'I do not have the strength of body or will that I once did. I''m glad there are noble pandaren like you to fight on for our people. You''ve come far, $n.', 19831), -- 29787
(29788, 1, 0, 0, 0, 0, 0, 0, 0, 'The spirits thank you, $c.', 19831), -- 29788
(29789, 1, 0, 0, 0, 0, 0, 0, 0, 'You come through, as you always have. You are truly one of my greatest students. I think you will be something the likes of which the world has never seen.', 19831), -- 29789
(29790, 1, 0, 0, 0, 0, 0, 0, 0, 'I know, $n... I know. Such is the way of things.', 19831), -- 29790
(29791, 1, 0, 0, 0, 0, 0, 0, 0, 'You have undergone a great honor, $c. Have you come back wiser for it?', 19831), -- 29791
(29792, 1, 0, 0, 0, 0, 0, 0, 0, 'Evil is rising from the seas and filling the forest. It''s not just tigers anymore... something far more sinister lurks in the shadows, waiting to take any pandaren unwise enough to stray out alone.$B$BYou are not safe here.', 19831), -- 29792
(29793, 1, 0, 0, 0, 0, 0, 0, 0, 'You make me proud, $n. You make all of us proud.', 19831), -- 29793
(29794, 1, 0, 0, 0, 0, 0, 0, 0, 'I have no idea who you people are, but fate surely smiled on us this day. Many more would be dead if not for the help of you and your friends. I am in your debt.', 19831), -- 29794
(29795, 1, 0, 0, 0, 0, 0, 0, 0, 'These are excellent! We''ll have them crafted into weapons in no time.', 19831), -- 29795
(29796, 1, 0, 0, 0, 0, 0, 0, 0, 'Your friend is out fighting to save my crew. Fiercely I might add. I''m afraid your message may have to wait.', 19831), -- 29796
(29797, 1, 0, 0, 0, 0, 0, 0, 0, 'These will do perfectly. I''ll get my medics to work immediately.$B$BThank you.', 19831), -- 29797
(29798, 1, 0, 0, 0, 0, 0, 0, 0, '<Aysa is clearly exhausted from the fight.>$B$BYour skills in battle... are unquestionable... $c.$B$B<Aysa catches her breath for a moment.>$B$BDid you save the escaped prisoners?  ...Where is Ji? Is he okay?', 19831), -- 29798
(30589, 1, 0, 0, 0, 0, 0, 0, 0, 'Korga sent you, eh? Well, I wouldn''t mind doing a number on that ship for my own reasons anyway, but it''s going to take some work.$B$BGive me a moment to think...', 19831), -- 30589
(30590, 1, 0, 0, 0, 0, 0, 0, 0, 'More than enough. I''ve got the main control panel constructed. We should be ready very soon!', 19831), -- 30590
(30591, 1, 0, 0, 0, 0, 0, 0, 0, 'These survivors are in your debt, $c.', 19831), -- 30591
(30767, 1, 0, 0, 0, 0, 0, 0, 0, 'The first step is done, but now we must save Shen-zin Su!', 19831); -- 30767

DELETE FROM `quest_details` WHERE `ID` IN (29665, 29782, 29784, 29785, 29786, 29787, 29788, 29789, 29790, 29791, 29792, 29793, 29794, 29795, 29796, 29797, 29798, 29799, 30589, 30590, 30591, 30767);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(29665, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29665
(29782, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29782
(29784, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29784
(29785, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29785
(29786, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29786
(29787, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29787
(29788, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29788
(29789, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29789
(29790, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29790
(29791, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29791
(29792, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29792
(29793, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29793
(29794, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29794
(29795, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29795
(29796, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29796
(29797, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29797
(29798, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29798
(29799, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 29799
(30589, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 30589
(30590, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 30590
(30591, 1, 0, 0, 0, 0, 0, 0, 0, 19831), -- 30591
(30767, 1, 0, 0, 0, 0, 0, 0, 0, 19831); -- 30767

DELETE FROM `quest_request_items` WHERE `ID` IN (29780, 29781, 29789, 29795, 29797, 29799, 30590);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`,`EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29780, 1, 0, 0, 0, 'Following the Huojin discipline often means making the hard decisions. This is one of those moments.', 20253), -- 29780
(29781, 1, 0, 0, 0, 'I''m somewhat impressed they hadn''t set their village on fire with these things.', 20253), -- 29781
(29789, 1, 0, 0, 0, 'Rest feels good. The burdens of life have become a great weight after so many years.', 20253), -- 29789
(29795, 1, 0, 0, 0, 'The Horde does not back down from a fight.', 20253), -- 29795
(29797, 1, 0, 0, 0, 'Did you find the boxes I spoke of?', 20253), -- 29797
(29799, 1, 0, 0, 0, 'We need to get the healers to the wound and keep them safe!', 20253), -- 29799
(30590, 1, 0, 0, 0, 'You''re in one piece. That''s a good sign.$B$BDid you get your hands on what I asked for?', 20253); -- 30590

DELETE FROM `npc_text` WHERE `ID` IN (18605, 18630, 18680);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(18605, 1, 0, 0, 0, 0, 0, 0, 0, 54594, 0, 0, 0, 0, 0, 0, 0, 19831), -- 18605
(18630, 1, 0, 0, 0, 0, 0, 0, 0, 54735, 0, 0, 0, 0, 0, 0, 0, 19831), -- 18630
(18680, 1, 0, 0, 0, 0, 0, 0, 0, 55002, 0, 0, 0, 0, 0, 0, 0, 19831); -- 18680
