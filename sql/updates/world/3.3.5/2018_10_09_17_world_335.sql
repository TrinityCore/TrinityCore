-- Earthcaller Franzahl
UPDATE `creature_template` SET `gossip_menu_id`=5812 WHERE `entry`=14348;

DELETE FROM `gossip_menu` WHERE `MenuID` IN (5812,5813,5814,5815,5816);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(5812,6985,0),
(5813,6986,0),
(5814,6987,0),
(5815,6988,0),
(5816,6989,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (5812,5813,5814,5815);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(5812,0,0,"Are you the Earthshaper capable of creating Elementium?",9576,1,1,5813,0,0,0,"",0,0),
(5813,0,0,"What do you know of it, Franzahl?",9578,1,1,5814,0,0,0,"",0,0),
(5814,0,0,"A fissure?",9580,1,1,5815,0,0,0,"",0,0),
(5815,0,0,"So what happened?",9582,1,1,5816,0,0,0,"",0,0);

DELETE FROM `npc_text` WHERE `ID` IN (6986,6987,6988,6989);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`) VALUES
(6986,"Elementium? I have not heard that word uttered from the mouth of a mortal in decades.","",9577,0,1,0,1,0,0,0,0),
(6987,"A former student of mine by the name of Krixix spent a lifetime attempting to make contact with the chained Gods of the underworld. He pursued that which would spring up from the ravaged earth... That which would form only as a result of the elements clashing in titanic conflict.$B$BElementium as it would be known to mortals.$B$BOne day, nearly a decade ago, Krixix's pursuit lead to a fissure forming in this very gorge.","",9579,0,1,0,1,0,1,0,0),
(6988,"Aye, he had done what was thought to be impossible. Out from the fissure sprung an agent of Therazane!$B$BFrom my vantage point, I could see the goblin holding conversation with the agent of the Old God. What happened after that was terrible...","",9581,0,1,0,1,0,1,0,0),
(6989,"The fissure closed and Krixix was gone! Swallowed whole!$B$BBe warned, $r, what you wish for could very well become that which you do not want. You play with beings and arcana that are older than time itself!$B$BShould Krixix be alive and should he have the information which you seek, you can be certain that he will not give up said information. He has faced terrors far worse than you could ever dream to perpetrate.","",9583,0,1,0,1,0,5,0,0);
