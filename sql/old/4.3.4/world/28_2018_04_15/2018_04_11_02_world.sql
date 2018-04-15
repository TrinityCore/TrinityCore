-- 
DELETE FROM `npc_text` WHERE `ID` IN (9148,9151,9153,9155,9158,14973,16059,17839,17982);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`) VALUES
(9148,"A glorious victory!","",14674,0,1,5,0,0,0,0,0),
(9151,"","I am here to give thanks to the one that saved my life.",14677,0,1,1,0,0,0,0,0),
(9153,"We are here to support our hero!","",14680,0,1,0,0,0,0,0,0),
(9155,"I have come to support the draenei champion!","",14682,0,1,5,0,0,0,0,0),
(9158,"We have traveled far to celebrate the hero of the draenei people.","",14685,0,1,1,0,0,0,0,0),
(14973,"Steady yourself, friend...$b$bThese next hours shall determine the fate of our clans.","",36413,0,1,0,0,0,0,0,0),
(16059,"<These baby murlocs seem to have been abandoned here.>","",41363,0,1,0,0,0,0,0,0),
(17982,"King Magni's fate is my responsibility and my shame. I should've counseled patience instead of encouraging him! His rush to complete the ritual without understanding it cost him his life and availed us nothing.","",51469,0,1,5,0,0,0,0,0);
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`, `text1_0`, `BroadcastTextID1`, `lang1`, `Probability1`, `em1_0`, `text2_0`, `BroadcastTextID2`, `lang2`, `Probability2`, `em2_0`, `text3_0`, `BroadcastTextID3`, `lang3`, `Probability3`, `em3_0`, `text4_0`, `BroadcastTextID4`, `lang4`, `Probability4`, `em4_0`) VALUES
(17839,"The cub tilts its head and looks at you expectantly. Shouldn't you know what to do, $g dad:mom;?",50755,0,1,0,"The cub bats one paw at a tiny insect, only taking note of your attention when the plaything flies away.",51339,0,1,0,"The cub nuzzles your hand and purrs.",51340,0,1,0,"Your little cub nips and paws at the air, eager to try out his hunting skills.",51342,0,1,0,"The cub sniffs your hand and decides you're not a threat... this time.",51343,0,1,0);
