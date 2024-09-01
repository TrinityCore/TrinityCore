-- The Emblazoned Runeblade (12619)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=12619;

-- Runeforging: Preparation For Battle (12842)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=12842;

-- The Endless Hunger (12848)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=12848;

-- The Eye Of Acherus (12636)
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=12636;

-- Death Comes From On High (12641)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=12641;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=12641;

-- Report To Scourge Commander Thalanor (12850)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=5 WHERE `ID`=12850;

-- If Chaos Drives, Let Suffering Hold The Reins (12678)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=12678;

-- Grand Theft Palomino (12680)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=12680;

-- Tonight We Dine In Havenshire (12679)
UPDATE `quest_details` SET `Emote1`=396,`Emote2`=396,`Emote3`=396,`EmoteDelay1`=25 WHERE `ID`=12679; 
UPDATE `quest_offer_reward` SET `Emote1`=396,`EmoteDelay1`=25 WHERE `ID`=12679;

-- Into the Realm of Shadows (12687)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=12687;

-- Gothik the Harvester (12697)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=1 WHERE `ID`=12697;

-- The Gift That Keeps On Giving (12698)
UPDATE `quest_details` SET `Emote1`=5,`Emote2`=25,`Emote3`=1,`Emote4`=1 WHERE `ID`=12698;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=12698;

-- An Attack Of Opportunity (12700)
UPDATE `quest_details` SET `Emote1`=5,`Emote2`=1,`Emote3`=1,`Emote4`=1 WHERE `ID`=12700;

-- Massacre At Light's Point (12701)
UPDATE `quest_details` SET `Emote1`=274,`Emote2`=1,`Emote3`=1,`Emote4`=1 WHERE `ID`=12701;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=12701;

-- Victory At Death's Breach! (12706)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=12706;

-- The Will Of The Lich King (12714)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=273,`Emote4`=25 WHERE `ID`=12714;

-- The Crypt of Remembrance (12715)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=1 WHERE `ID`=12715;

-- The Plaguebringer's Request (12716)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=5,`Emote3`=1,`Emote4`=6 WHERE `ID`=12716;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=12716;

-- Noth's Special Brew (12717)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=12717;

-- Nowhere To Run And Nowhere To Hide (12719)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=12719;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=12719;

-- Lambs To The Slaughter (12722)
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12722;

-- How To Win Friends And Influence Enemies (12720)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=12720;

-- Behind Scarlet Lines (12723)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=12723;

-- The Path Of The Righteous Crusader (12724)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=12724;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=12724;

-- Brothers In Death (12725)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=5 WHERE `ID`=12725;

-- A Cry For Vengeance! (12738)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=12738;

-- A Special Surprise (For all races)
DELETE FROM `quest_details` WHERE `ID` IN (12739,12742,12743,12744,12745,12746,12747,12748,12749,12750);
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(12739,1,1,1,1,0,0,0,0,0),
(12742,1,1,1,1,0,0,0,0,0),
(12743,1,1,1,1,0,0,0,0,0),
(12744,1,1,1,1,0,0,0,0,0),
(12745,1,1,1,1,0,0,0,0,0),
(12746,1,1,1,1,0,0,0,0,0),
(12747,1,1,1,1,0,0,0,0,0),
(12748,1,1,1,1,0,0,0,0,0),
(12749,1,1,1,1,0,0,0,0,0),
(12750,1,1,1,1,0,0,0,0,0);

-- A Sort Of Homecoming (12751)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=66 WHERE `ID`=12751;

-- Ambush At The Overlook (12754)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=25 WHERE `ID`=12754;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=12754;

-- A Meeting With Fate (12755)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=1 WHERE `ID`=12755;

-- The Scarlet Onslaught Emerges (12756)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=15 WHERE `ID`=12756;

-- Scarlet Armies Approach... (12757)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=12757;

-- The Scarlet Apocalypse (12778)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=1 WHERE `ID`=12778;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=12778;

-- An End To All Things... (12779)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=25 WHERE `ID`=12779;
UPDATE `quest_offer_reward` SET `Emote1`=25,`Emote2`=1,`Emote3`=1 WHERE `ID`=12779;

-- The Lich King's Command (12800)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=25 WHERE `ID`=12800;

-- The Light of Dawn (12801)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=15 WHERE `ID`=12801;

-- Taking Back Acherus (13165)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=13165;

-- The Battle For The Ebon Hold (13166)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=13166;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=13166;

-- Where Kings Walk (13188)
UPDATE `quest_details` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=13188;
