DELETE FROM `page_text` WHERE `entry` IN (3470, 3471);
INSERT INTO `page_text` (`entry`, `text`, `next_page`, `WDBVerified`) VALUES
(3470, 'The sheer vastness of the nether is no excuse for using it as a garbage repository! Your Portal and Teleport spells are a great privilege and responsibility, and carelessly casting the waste from your noontime meals into a portal could have GRAVE CONSEQUENCES for all of Azeroth! Please secure all objects when traveling via portal and report any lost objects to the Kirin Tor council at once. Read the latest edition of "Thinking with Portals - A Memorandum on Proper Portal Usage" for all information regarding portal use. ', 3471, 17538), -- 3470
(3471, 'If this problem grows any further out of hand, I will be forced to insist that all portal travelers relinquish their weaponry and personal hygiene supplies before embarking. And the next time my lecture notes appear among the rubbish, I will personally transform the heads of all apprentices into dunce caps!

--Archmage Runeweaver 
', 0, 17538); -- 3471

UPDATE `page_text` SET `text`='As you are all well aware, we as an organization make a regular habit of combing the local reaches of the twisting nether for misplaced objects. This has turned up all manner of wayward treasure, from errant magical essences to crackling shards of mystic power to entire suits of armor and powerful weaponry. Increasingly of late, however, we have also begun to turn up garbage and refuse as well.', `next_page`=3470, `WDBVerified`=17538 WHERE `entry`=3469; -- 3469
