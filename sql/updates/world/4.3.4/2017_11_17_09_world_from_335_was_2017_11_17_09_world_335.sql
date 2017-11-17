DELETE FROM `quest_greeting` WHERE `ID` IN (3390,3339,3995,4049,264,3519,392,900,2080,3337,3567,4791,5767,344,3847,11862);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(3390,0,0,0,"The Barrens holds a variety of substances for which we, the apothecaries of Lordaeron may find use.",0), -- Apothecary Helbrim
(344,0,5,0,"Redridge is awash in chaos!",0), -- Magistrate Solomon
(3339,0,0,0,"This had better be good...",0), -- Captain Thalo'thas Brightsun
(3995,0,5,0,"The spirits are restless!",0), -- Witch Doctor Jin'Zil
(4049,0,0,0,"The spirit of Stonetalon weeps... It weeps from its mountain peaks, to its rivers, to its severed, dying trees.",0), -- Seereth Stonebreak
(264,0,0,0,"At ease, $c. If you are just passing though I suggest you stick to the roads and only travel by day. If your business is here in Darkshire, consider lending your abilities to the Night Watch. Our Skill is unquestionable but our numbers are small.",0), -- Commander Althea Ebonlocke
(3519,0,0,0,"I, Arynia Cloudsbreak, have been tasked with protecting the sanctity of the Oracle Grove.",0), -- Sentinel Arynia Cloudsbreak
(392,0,0,0,"Do not be alarmed, $r.  I have long since passed from this land but I intend no harm to your kind.  I have witnessed too much death in my time.  My only wish now is for peace.  Perhaps you can help my cause.",0), -- Captain Grayson
(900,0,6,0,"What business brings you before the Court of Lakeshire and the Honorable Magistrate Solomon?",0), -- Bailiff Conacher
(2080,0,1,0,"The creation of Teldrassil was a grand achievement, but now the world must shift to regain its balance.",0), -- Denalan
(3337,0,0,0,"The heft of an axe, the battlecry of your allies, the spray of blood in your face. These are the things a warrior craves, $n. I will carve out The Barrens with my sword in the name of the Horde.",0), -- Kargal Battlescar
(3567,0,1,0,"Well met, $n. It is good to see that $cs like yourself are taking an active part in protecting the groves.",0), -- Tallonkai Swiftroot
(4791,0,1,0,"We may not be in open war with the Alliance, but blood is still shed between us.",0), -- Nazeer Bloodpike
(5767,0,1,0,"Our only hope is to create something good from an already bad situation.",0), -- Nalpak
(3847,0,0,0,"Ashenvale is a lush forest, brimming with life. It is a pleasure to walk down its secret paths in search of herbs, but one must take care. The forest is not without its dangers.",0), -- Orendil Broadleaf
(11862,0,0,0,"",0); -- Tsunaman

UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=234;
